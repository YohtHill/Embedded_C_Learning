# PCB 工程项目（PCB_Prj）

> 使用 **Altium Designer** 设计的 PCB 板卡项目，共 3 个。每个项目包含完整的工程文件。

## 项目列表

| 项目 | 说明 | 状态 |
|------|------|------|
| [BF83080C_V1.0](BF83080C_V1.0/) | BF83080C 板卡 V1.0 | ✅ |
| [BM22192DA06](BM22192DA06/) | BM22192DA06 板卡（作者 PIJIAKUN）| ✅ |
| [BM3218+BF83112](BM3218+BF83112/) | BM3218 + BF83112 板卡（Final Version）| ✅ |

## 每个项目的标准文件结构

```
项目名/
├── SCH/       # 原理图（.schdoc / .SchDocPreview）
├── PCB/       # PCB 版图（.pcbdoc）
├── Gerber/    # 生产文件（Gerber/ODB++，供 PCB 厂生产）
├── BOM/       # 物料清单（BOM，元器件采购用）
├── SMT/       # 贴片文件（坐标/位号，供 SMT 贴片厂）
├── DWG/       # 结构图（机械尺寸）
└── DXF/       # 外形/结构参考
```

## 文件类型说明

| 类型 | 用途 |
|------|------|
| `.schdoc` | Altium 原理图 |
| `.pcbdoc` | Altium PCB 版图 |
| Gerber 系列（.GTL/.GBL/.GTO...）| 生产光绘文件 |
| `.xlsx` / `.csv` | BOM 物料清单 |
| `.dwg` / `.dxf` | 结构机械图 |
| `.pdf` | 输出文档（图纸/报告）|
| `.zip` | 打包文件 |

## 说明

- 每个项目均为完整可交付的 PCB 设计工程
- 含设计 → 生产 → 贴片全流程文件
