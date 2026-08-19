# PCB Projects (PCB_Prj)

> PCB board projects designed with **Altium Designer**, 6 projects in total. Each project contains the complete engineering files.

[中文](README.md) | **English**

## Project List

| Project | Description | Status | Updated |
|---------|-------------|--------|---------|
| [CCM4201S_MAIN_Board_V1-PIJIAKUN_20260819](CCM4201S_MAIN_Board_V1-PIJIAKUN_20260819/) | CCM4201S development board | ✅ Completed | 2026-08-19 |
| [BM43112DC02_PIJIAKUN](BM43112DC02_PIJIAKUN/) | BM43112DC02 fingerprint module | ✅ Completed | 2026-08-17 |
| [VB2032-241203_PIJIAKUN](VB2032-241203_PIJIAKUN/) | VB2032 fingerprint module | ✅ Completed | 2026-08-13 |
| [BF83080C_V1.0](BF83080C_V1.0/) | BF83080C board V1.0 | ✅ Completed | 2026-08-12 |
| [BM22192DA06](BM22192DA06/) | BM22192DA06 board | ✅ Completed | 2026-08-07 |
| [BM3218+BF83112](BM3218+BF83112/) | BM3218 + BF83112 board (Final Version) | ✅ Completed | 2026-08-03 |

## Standard File Structure per Project

```
project/
├── SCH/       # Schematic (.schdoc / .SchDocPreview)
├── PCB/       # PCB layout (.pcbdoc)
├── Gerber/    # Manufacturing files (Gerber/ODB++, for PCB fab)
├── BOM/       # Bill of Materials (for component purchasing)
├── SMT/       # Assembly files (coordinates/refdes, for SMT assembly)
├── DWG/       # Mechanical drawings (dimensions)
└── DXF/       # Outline/structure references
```

## File Type Reference

| Type | Purpose |
|------|---------|
| `.schdoc` | Altium schematic |
| `.pcbdoc` | Altium PCB layout |
| Gerber series (.GTL/.GBL/.GTO...) | Manufacturing photoplot files |
| `.xlsx` / `.csv` | BOM |
| `.dwg` / `.dxf` | Mechanical drawings |
| `.pdf` | Output documents (drawings/reports) |
| `.zip` | Packaged files |

## Notes

- Each project is a complete, deliverable PCB design
- Includes the full flow from design → manufacturing → assembly
