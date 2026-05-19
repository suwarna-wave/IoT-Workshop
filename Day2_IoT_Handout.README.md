Day 2 — ESP32 Networking & HTTP — Handout export

This repository contains `day2.html` as the canonical Day 2 handout. The file has been updated to reuse the main site `styles.css` and the site header/footer for a seamless experience.

To produce a PDF handout named `Day2_IoT_Handout.pdf` you can use one of the commands below on a machine with a headless browser or `wkhtmltopdf` installed.

Using Google Chrome / Chromium (recommended):

```bash
# from the repository root
google-chrome --headless --disable-gpu --no-sandbox --print-to-pdf=Day2_IoT_Handout.pdf day2.html
# or
chromium --headless --disable-gpu --no-sandbox --print-to-pdf=Day2_IoT_Handout.pdf day2.html
```

Using wkhtmltopdf:

```bash
wkhtmltopdf day2.html Day2_IoT_Handout.pdf
```

If you prefer a manual approach: open `day2.html` in a modern browser, choose Print → Save as PDF.

Notes and checks performed:
- Inline CSS removed; `styles.css` is used for layout and typography consistency.
- Header and footer replaced with the site's header/footer to keep navigation consistent.
- The handsout link is already present in `index.html` and points to `day2.html`.
- The small JavaScript helpers (`copyCode`, `openTab`) were preserved.

If you want, I can generate the PDF here if you allow installing a converter or running a headless browser in this environment. Otherwise run one of the commands above locally and the generated `Day2_IoT_Handout.pdf` will match the site styling.