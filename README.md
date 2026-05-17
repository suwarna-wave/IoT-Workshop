# IoT Workshop — 8‑Day Hands‑On Course

A compact, practical IoT workshop containing eight daily exercises and a single-page demo site. Each day builds on the previous one with clear examples, assets, and small projects you can run locally in a browser.

**Status:** Ready-to-run static site (HTML/CSS). No build step required.

## What's included
- Interactive pages for each day: an 8-day curriculum with demos and notes.
- A single entry point: [index.html](index.html)
- Styling in [styles.css](styles.css)

## Prerequisites
- A modern web browser (Chrome, Firefox, Edge, Safari)
- (Optional) Python 3 or Node.js to run a local static server

## Quick start
Option 1 — Open locally

1. Open [index.html](index.html) directly in your browser.

Option 2 — Run a simple local server (recommended for AJAX or module-based examples)


## File structure
The repository is intentionally small and self-contained:

- [index.html](index.html) — Landing page / navigation
- [styles.css](styles.css) — Global styles
- [day0.html](day0.html) — Day 0: Introduction & setup
- [day1.html](day1.html) — Day 1: Basic sensors and reading data
- [day2.html](day2.html) — Day 2: Actuators and output control
- [day3.html](day3.html) — Day 3: Communication protocols (HTTP/MQTT basics)
- [day4.html](day4.html) — Day 4: Data logging and persistence
- [day5.html](day5.html) — Day 5: Visualizing sensor data
- [day6.html](day6.html) — Day 6: Edge processing and simple ML
- [day7.html](day7.html) — Day 7: Project wrap-up & next steps

## Day‑by‑day summary
- Day 0 — Orientation, tools, and environment setup.
- Day 1 — Read sensor values and display them in the browser.
- Day 2 — Control LEDs, motors, and other actuators from the UI.
- Day 3 — Send and receive messages using HTTP and learn basic MQTT concepts.
- Day 4 — Store readings locally and explore simple persistence strategies.
- Day 5 — Build charts and dashboards to visualize live or historical data.
- Day 6 — Run lightweight processing on the device (filters, thresholds, simple ML examples).
- Day 7 — Combine everything into a small capstone demo and plan next steps.

## How to use
- Prefer running a local server (see Quick start) to avoid file:// CORS issues.
- Open [index.html](index.html) and use the navigation to jump to each day's demo.
- Tweak the HTML/CSS and experiment — the site is designed to be a learning sandbox.

## Contributing
- Feel free to open issues or submit pull requests with improvements, corrections, or new days/lessons.
- Keep changes small and focused; include a short description of the learning objective for any new day added.

## License
MIT License — see [LICENSE](LICENSE) for details.

## Contact
If you want help extending the workshop or turning a day into a standalone lab, open an issue or contact the maintainer.

----
Updated README — concise guide to run and extend the IoT Workshop.
