from dataclasses import dataclass
import json
import os
from typing import Optional

def gen_description(description: str):
    result = ""

    tag = None
    for line in description.split("\n")[1:-1]:
        if line.startswith(" * "):
            line = line.removeprefix(" * ")
        elif line.startswith("   "):
            line = line.removeprefix("   ")

        if ":" in line:
            tag = line[:line.index(":")]

        if tag not in ("Author", "Date", "License", "Source", "Status"):
            result += line + "\n"

    return result

@dataclass
class Snippet:
    name: str
    prefix: str
    body: str
    description: Optional[str]

    def to_json(self):
        result = {
            "scope": "cpp",
            "prefix": self.prefix,
            "body": self.body
        }
        if self.description is not None:
            result["description"] = self.description
        return result
    
    @staticmethod
    def from_file(filename: str, ext: str):
        with open(filename + ext) as f:
            content = f.read()
        prefix = filename.removeprefix("content/").lower().replace("/", ":")

        if content.startswith("/**"):
            split = content.index("*/")+2

            description = gen_description(content[:split])
            content = content[split:].lstrip()
            if content.startswith("#pragma once"):
                content = content.removeprefix("#pragma once").lstrip()
        else:
            description = None

        return Snippet(os.path.basename(filename), f"@{prefix}", content, description)

snippets = []

for root, dirs, files in os.walk("content"):
    for file in files:
        for ext in (".cpp", ".h"):
            if file.endswith(ext):
                snippets.append(Snippet.from_file(os.path.join(root, file.removesuffix(ext)), ext))

print(json.dumps({snippet.name: snippet.to_json() for snippet in snippets}, indent=4))
