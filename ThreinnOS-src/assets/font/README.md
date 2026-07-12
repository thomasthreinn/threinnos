# ThreinnOS Fonts

This directory contains the original font files used by ThreinnOS.

These files are never used directly by the kernel.

Instead, they are converted into C source files by the
`font-converter` tool.

Generated files are stored inside:

kernel/src/video/generated/

Current fonts:

- JetBrainsMono-Regular.ttf
  Main monospace font for terminal and user interface.

- Terminus16.bdf
  Bitmap font used during the boot sequence and early kernel.

The original files should never be modified manually.

If another font is added, simply place it in this directory and
regenerate the generated files using the font converter.
