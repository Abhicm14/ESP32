# Contributing to ESP32 Learning Path

Welcome! Thank you for taking the time to help make this ESP32 learning roadmap better for everyone. Whether you are fixing a typo, clarifying an explanation, improving wiring diagrams, or adding code examples, your contribution is greatly appreciated.

This repository is designed for **complete beginners**, students, and engineers making the transition from high-level prototyping to professional embedded systems with **ESP-IDF**. Keeping explanations simple, clear, and beginner-first is our top priority!

---

## Ways to Contribute

We welcome contributions across several areas:
- **Documentation Corrections**: Fixing errors, clarifying confusing sentences, and correcting pin references.
- **Lesson Improvements**: Making explanations easier to grasp for non-ECE learners and complete beginners.
- **New Code Examples and Wiring Diagrams**: Adding clean, tested examples (both ESP-IDF and Arduino reference code) and clear circuit diagrams.
- **Troubleshooting Tips**: Documenting common beginner pitfalls, setup quirks, or board-specific behaviors you encountered.

---

## Contribution Guidelines

To ensure code quality and keep the repository clean and accessible:

1. **Keep Pull Requests Small and Focused**:
   - Address one topic, bug, or lesson improvement per pull request.
   - Small pull requests are reviewed and merged much faster!

2. **Use Simple, Plain Language**:
   - Avoid unnecessary academic jargon in early phases.
   - If an advanced technical term is needed, explain what it means in plain English with an everyday analogy.

3. **Test All ESP-IDF Examples**:
   - Any firmware code contributed must build cleanly without warnings or errors.
   - In your PR description, please specify:
     - **Board Model** (for example, ESP32-WROOM-32 38-pin DevKit V1)
     - **ESP-IDF Version** (for example, Tested with ESP-IDF v6.1 or v5.x)
     - **Arduino Core Version** (if an Arduino sketch is provided)
     - **Wiring Used** (exact pin numbers, resistor values, and power rails)

4. **Never Commit Build Artifacts or Generated Files**:
   - Do NOT commit:
     - `build/` directories
     - `sdkconfig` or `sdkconfig.old`
     - `managed_components/`
     - Binaries (`.bin`, `.elf`, `.map`)
     - Build logs or IDE cache (`.vscode/` local state, `.idea/`)
   - Verify with `git status` before committing.

5. **Follow Conventional Commits**:
   - Use clear, descriptive commit messages.

   **Examples**:
   - `docs(day09): improve GPIO wiring explanation`
   - `feat(day10): add button input ESP-IDF example`
   - `fix(day09): correct LED resistor calculation`
   - `docs(setup): clarify COM port detection in Windows`

---

## Step-by-Step Workflow

1. **Fork the Repository** on GitHub.
2. **Clone your fork** locally:
   ```bash
   git clone https://github.com/<your-username>/ESP32.git
   cd ESP32
   ```
3. **Create a descriptive feature branch**:
   ```bash
   git checkout -b docs/clarify-gpio04-wiring
   ```
4. **Make your edits** and verify all links and Markdown formatting.
5. **Stage only the files you edited** (never use `git add .`):
   ```bash
   git add docs/TROUBLESHOOTING.md
   git commit -m "docs(troubleshooting): add note on USB data cable issues"
   ```
6. **Push to your fork** and open a Pull Request against `main`.

---

## Need Help or Have Questions?

- Open an issue using our [GitHub Issue Templates](.github/ISSUE_TEMPLATE/).
- Check our [Beginner Troubleshooting Guide](docs/TROUBLESHOOTING.md).
- Join the discussion and share your learning feedback!
