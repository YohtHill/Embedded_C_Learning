# Power Source Testing

> Testing the **BF85112B** power IC module to observe power states at different time bases.

[中文](README.md) | **English**

## Test Target

- **BF85112B** IC module
- Samples: BF85112B_2, BF85112B_3

## Time Bases

Tested at the following time bases:

```
50ms / 100ms / 150ms / 200ms / 250ms / 300ms
```

## State Categories

Multiple test images are captured per time base, categorized by state:

| State | Description |
|-------|-------------|
| **Capture** | Waveform acquisition |
| **FD** | Fingerprint detection (FingerDetect) |
| **Idle** | Standby |

## Image Directory Structure

```
PowerSourceTesting_Img/
├── BF85112B_2/          # Sample 2
│   ├── 50ms/            # 50ms base
│   │   ├── 50ms_Capture.png
│   │   ├── 50ms_FD.png
│   │   └── 50ms_Idle.png
│   ├── 100ms/ ~ 300ms/  # Other time bases
└── BF85112B_3/          # Sample 3
    ├── 50ms/ ~ 300ms/
```

## Notes

- Images are organized in a **sample → time base → state** 3-level hierarchy
- `PowerSourceTesting_Report/` is the report directory (to be added)
