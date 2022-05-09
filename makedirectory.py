from os import makedirs, path

with open("./README.md") as fp:
    lines = fp.readlines()

year = 22
month = 1
date = 1

for line in lines[4:]:
    monthdate, num, url = (x.strip() for x in line.split("|")[1:4])
    if monthdate.strip():
        month, date = (int(x) for x in monthdate.split("/"))

    readme_dir = f"./{year:02d}-{month:02d}-{date:02d}/{num}/"

    if path.exists(f"{readme_dir}/README.md"):
        continue

    makedirs(readme_dir, exist_ok=True)

    with open(f"{readme_dir}/README.md", "w") as fp:
        readme_lines = []
        readme_lines.append(f"# {year:02d}-{month:02d}-{date:02d} {num}번 문제")
        readme_lines.append("")
        readme_lines.append(f"## {url}")
        readme_lines.append("")
        fp.write("\n".join(readme_lines))
