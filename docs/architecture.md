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
graph TD;
    Start[Start Game] --> Dialogue1[Initial Dialogue]
    Dialogue1 -->|Choice 1| Path1[Intermediate Event 1]
    Dialogue1 -->|Choice 2| Path2[Intermediate Event 2]
    Path1 -->|Choice A| Ending1[Outcome: Victory]
    Path1 -->|Choice B| Ending2[Outcome: Betrayal]
    Path2 -->|Choice C| Ending3[Outcome: Escape]
    Path2 -->|Choice D| Ending4[Outcome: Defeat]
    
    