# WARNING: DO NOT build from source at this time. Previous versions were written in C++, but the codebase is being ported to Rust. The Rust port cannot access the database or the config file, only hardcoded values are supported.

## Binaries
Both Linux and Windows Binaries will be provided.

## Build
As it is written in Rust, just install rustup:
- Linux/MacOS `curl --proto '=https' --tlsv1.3 https://sh.rustup.rs -sSf | sh`
- Windows [Instructions](https://www.rust-lang.org/tools/install)
```sh
  git clone https://github.com/GlitchyCrafting/WDHANY.git
  cd WDHANY
  cargo build --release
  cd target/release
  ./wdhany
  # ./wdhany.exe on Windows
```

## The Platform
I created the platform to have the verbosity of W3Schools in the lessons, but in the format of FreeCodeCamp. The UI is built to be minimal using readable fonts, no more "Is this an l, or an I?", and a color scheme that's easy on the eyes. It has an online editor so nothing needs to be installed on the user's computer. It also has a live preview to allow for better learning, visualization is very helpful in design to know what code does what. No account creation is needed as everything is stored in a single cookie, though this may change in the future to allow more options for anyone using the platform.

## Technical Information
The server is written in [Rust](https://www.rust-lang.org), all the crates used are in [Cargo.toml](Cargo.toml). The online editor is the [Ace Library](https://ace.c9.io/) written in Javascript. The UI uses the [Dracula Color Scheme](https://draculatheme.com/). There is a live preview that uses Javascript Blobs to get code from the editor and display it in an IFrame.
