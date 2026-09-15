# Twentynine Robotics Guides

Source for the public Twentynine Robotics documentation website. The site is written in Markdown and uses GitHub Pages' built-in Jekyll processing with plain HTML and CSS.

## Publish on GitHub Pages

1. Create a public GitHub repository named `twentynine-robotics-guides`.
2. Push this repository's `main` branch to GitHub.
3. Open **Settings > Pages** in the GitHub repository.
4. Under **Build and deployment**, select **Deploy from a branch**.
5. Select the `main` branch and the `/docs` folder, then save.
6. Wait for the Pages deployment to finish and use the **Visit site** button.

The expected project URL for the current owner is:

```text
https://aj-morales99.github.io/twentynine-robotics-guides/
```

If the account or repository name changes, update `url` and `baseurl` in `docs/_config.yml`.

## Documentation structure

```text
docs/
  index.md
  changelog.md
  mini-hunter/
  hammerhead/
  assets/
```

The Mini Hunter guide is usable without images. Numbered image placeholders are public, but the photographer's checklist is intentionally stored outside this public repository in `../private-maintainer-notes/`. Add reviewed web images gradually in `docs/assets/images/mini-hunter/`.
