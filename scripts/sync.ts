import { parse } from "std/yaml/mod.ts";
import type { Config, Solve } from "./types.ts";

const config = parse(Deno.readTextFileSync("./config.yml")) as Config;
const ext = config.extension;

for (const category of Object.keys(config.categories)) {
  console.log("sync:", config.categories[category].name);
  const categoryId = config.categories[category].id;
  const name = config.categories[category].name;
  const solve = JSON.parse(
    Deno.readTextFileSync(`./${categoryId}/solve.json`),
  ) as Solve;

  const languages = new Set<string>();

  for (const key of Object.keys(solve)) {
    for (const lang of Object.keys(solve[key].submissions)) {
      if (!languages.has(lang)) {
        languages.add(lang);
      }
    }
  }

  const content = [`# ${name}`, ""];
  let header = "|#|Problem|";
  let separator = "|:--:|----|";

  for (const lang of languages) {
    header += `${lang}|`;
    separator += ":--:|";
    if (!ext[lang]) {
      console.warn(
        `%c[Warn] missing extension for ${lang} in config.`,
        "color: yellow",
      );
      ext[lang] = "unknown";
    }
  }

  content.push(header);
  content.push(separator);

  for (const key of Object.keys(solve)) {
    let entry = `|${key}|[${solve[key].name}](${solve[key].url})|`;
    for (const lang of languages) {
      if (solve[key].submissions[lang]) {
        entry += `[✅](${solve[key].submissions[lang]})/[📝](${key}/main.${
          ext[lang]
        })|`;
      } else {
        entry += "|";
      }
    }
    content.push(entry);
  }
  Deno.writeTextFileSync(`./${categoryId}/README.md`, content.join("\n"));
}
