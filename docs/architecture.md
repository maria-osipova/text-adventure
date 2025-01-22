# game architecture

this document outlines the architecture of the text-based adventure game.

---

## overview

the game is structured into the following components:
- **core logic**: handles user input, story progression, and decision-making.
- **dialogue system**: reads dialogues from `dialogues.json` and dynamically displays them.
- **JSON integration**: uses `jsoncpp` for managing game dialogues and data.

---

## flowchart

```mermaid
%%{ init: { "themeVariables": { "fontFamily": "'Press Start 2P', monospace" } } }%%
graph TD;
    Start[Start Game] --> Dialogue[Initial Dialogue]
    Dialogue -->|Choice 1| Path1[Intermediate Event 1]
    Dialogue -->|Choice 2| Path2[Intermediate Event 2]
    Path1 -->|Choice A| Ending1[Outcome: Victory]
    Path1 -->|Choice B| Ending2[Outcome: Betrayal]
    Path2 -->|Choice C| Ending3[Outcome: Escape]
    Path2 -->|Choice D| Ending4[Outcome: Defeat]

    %% customization of colours and style
    classDef default fill:#f9, stroke:#333, stroke-width:2px, font-size:12px; font-style: 