# 🐛 Vectorisation Formatting (MACOS support only - Temporary)

## Summary
- Static wrapper functions around float & doubles processing per platform.
- Formats being supported (In progress & open to other libraries):
  - [ ] Apple Accelerate & VDSP (In Progress).
  - [ ] Windows Intel ipp (Supporting in the near future)

## Why use a functional Style?
Functional allows for function overloading to extend support for any platform, without having to rewrite algorithms per platform.
So, Even if I want to move to embedded or linux, or even support a platform with no inbuilt vectorisation. It's completely open.

## Interface Implementation details
- Implement functions with seperate output pointer to allowing for the most amount of customisation.
- Stides or intervals are customisable per buffer (⚠️ At the moment there is no bounds checks).
- Functions are separated in nested namespaces to be more explicit.
- Future changes: std::span will be replacing the raw pointers at some point (🛟 It's a lot saver).

## Including, Linking & Building
- Wrappers are included inside VIVI DSP at the moment as I write the VIVI_DSP library.
- External Dependencies:
  - Catch2 is being used for unit testing wrapper functions (Common sense testing).
  - Accelerate (VDSP) for macOS.
