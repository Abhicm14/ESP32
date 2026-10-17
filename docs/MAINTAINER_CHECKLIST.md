# Repository Maintainer and Review Checklist

This checklist guides repository maintainers when adding lessons, reviewing community Pull Requests, and preparing future Continuous Integration (CI) workflows.

---

## Pull Request and Contribution Review Checklist

Before merging any pull request:

- [ ] **No Build Artifacts Staged**:
  - Verify that `build/`, `sdkconfig`, `sdkconfig.old`, `managed_components/`, binaries (`.bin`, `.elf`), and temporary IDE files (`.vscode/`, `.idea/`) are **NOT** committed.
- [ ] **Beginner Language Maintained**:
  - Content should be understandable by 12th-pass or non-ECE learners.
  - Complex terms must have everyday analogies.
- [ ] **Hardware Compatibility and Safety**:
  - Voltage levels are clearly specified as 3.3V.
  - Current-limiting resistors (220 ohm / 330 ohm) are included in all LED schematics.
  - No 5V logic connected directly to ESP32 GPIOs.
  - Safe GPIO pins are selected (avoiding GPIO 6 to 11 and strapping pins).
- [ ] **Dual Framework Clarity**:
  - If Arduino sketches are included, confirm they are presented as companion/reference examples and not as replacements for ESP-IDF.
- [ ] **Working ESP-IDF Code**:
  - The firmware must compile without errors or warnings.
  - Hardware model and ESP-IDF version (tested with ESP-IDF v6.1) must be stated.

---

## Future Continuous Integration (CI/CD) Guidance

Automated build testing ensures that sample code continues to compile across new framework releases. Follow these steps when setting up GitHub Actions in Phase 21:

1. **Commit a Clean, Tested ESP-IDF Example First**:
   - Do not add CI until at least one complete, self-contained project (like Day 9 GPIO Blink or Phase 1 System Info) is committed and verified locally.
2. **Setup ESP-IDF Docker Container in GitHub Actions**:
   - Use the official Espressif container matching the repository target environment:
     `espressif/idf:v6.1` (or latest verified release).
   - Run compilation checks using:
     ```yaml
     - name: Build Firmware
       run: |
         cd firmware/phase02_digital_io/day09_gpio_output
         idf.py build
     ```
3. **Add Build Badge Only After Verification**:
   - Once the workflow runs successfully and reliably passes, add the GitHub Actions build status badge to the root `README.md`.
4. **Dependencies and Component Manager**:
   - Ensure `dependencies.lock` is tracked if external component versions need pinning.

---

## Release and Milestone Checklist

- [ ] Check off completed days in `DAILY_TRACKER.md`.
- [ ] Update completion percentage truthfully (for example, `8 / 350 Days`).
- [ ] Ensure all internal links in `README.md`, `START_HERE.md`, and phase READMEs resolve correctly.
- [ ] Keep git history clean with conventional commits (`feat:`, `docs:`, `fix:`).
