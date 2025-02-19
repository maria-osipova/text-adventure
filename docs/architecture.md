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
graph TD
    A[Start Game] --> B[Load Dialogues & Greetings]
    B --> C[Big Adventure Dialogue]
    C --> D[Wait for Input]
    D --> E{Check Readiness<br>yes/no}
    E -- no --> F[Exit Game]
    E -- yes --> G[Continue]
    G --> H{Gender Prompt<br>man/woman}
    H -- invalid --> H
    H -- valid --> I[Name Prompt]
    I -- invalid --> I
    I --> J[Bar Intro & Choice<br>man/woman]
    J -- invalid --> J
    J -- valid --> K[Initialize Stats: courage=0, generosity=0, trust=0]
    K --> L[Sea Adventure]

    L --> M[Storm Question<br>yes/no]
    M -- yes --> N[courage++]
    M -- no --> O[courage--]
    N --> P[Share Food?<br>yes/no]
    O --> P
    P -- yes --> Q[generosity++]
    P -- no --> R[generosity--]
    Q --> S[Faint Light?<br>yes/no]
    R --> S
    S -- yes --> T[trust++]
    S -- no --> U[trust--]
    T --> V{Final Choice<br>Continue yes/no}
    U --> V
    V -- no --> W[Stay Choice & End]
    V -- yes --> X[Story Continuation]

    X --> Y[Push Boat?<br>yes/no]
    Y -- yes --> Z[courage++]
    Y -- no --> AA[courage--]
    Z --> AB[Loyalty?<br>yes/no]
    AA --> AB
    AB -- yes --> AC[trust++]
    AB -- no --> AD[trust--]
    AC --> AE{Ask or Silent?}
    AD --> AE
    AE -- ask --> AF[trust++]
    AE -- silent --> AG
    AF --> AH[Landing]
    AG --> AH

    AH --> AI[Determine Ending Based on Stats]
    AI --> AJ[One of 8 Endings]
    AJ --> AK[Show Final Stats & End]


    %% customization of colours and style
    classDef default fill:#f9, stroke:#333, stroke-width:2px, font-size:12px; font-style: 