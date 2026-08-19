# Hardware Design Notes (Internship Accumulation)

> This directory records **embedded hardware design** knowledge accumulated during my internship, mainly covering practical experience in PCB design, FPC flex design, ESD protection, and fingerprint module design.

[中文](README.md) | **English**

## Contents

| Folder/File | Content |
|------------|---------|
| `NOTE_FILE/Intern_note.md` | Internship notes: embedded fingerprint FD mode, FPC design rules |
| `NOTE_FILE/Module_Design_Skills.md` | Module design skills: PCB layout, routing, 4-layer board design |
| `ESD_GND_Img/` | ESD grounding design illustrations |
| `FPC_img/` | FPC flex design images (16) |
| `LGA_Img/` | LGA package design images |
| `FD_Img/` | Fingerprint (FingerDetect) related design images |
| `FingerIC_Design_Img/` | Fingerprint IC design images |
| `Module_Design_Skills_Img/` | Module design skills illustrations (22) |

## Knowledge Overview

### 1. Fingerprint Module Design (Intern_note.md)
- **Fingerprint power**: LDO selection (output current ≥250mA, fast response), recommend a dedicated LDO
- **FPC design rules**: routing length <120mm, peripheral components ≤30mm from routing, power trace width ≥0.2mm
- **Signal integrity**: SPI signals on the same layer, CLK shielded with GND, vertical routing between layers
- **ESD protection**: TVS to ESD-GND, metal ring for static discharge, solid GND copper wrapping signals

### 2. Module Design Skills (Module_Design_Skills.md)
- **Layout principles**: prioritize connector, RGB LED, fingerprint IC, metal ring placement
- **Modular layout**: use schematic-PCB cross-selection to place functional modules separately
- **Routing priority**: SPI signals, high-voltage signals, differential signals first; place decoupling caps/TVS close
- **4-layer board design**: IC layer/routing layer/GND layer/component layer; signals pass through caps and TVS before entering the IC
- **Package design**: bottom-view chips (QFN packages) require mirror flip on the top layer

## Image Notes

All `.png` images are design illustrations/real photos, used with the corresponding notes to help understand PCB layout, FPC routing, ESD grounding, and other design points.

---

*Continuously updated, recording hardware design experience learned during the internship.*
