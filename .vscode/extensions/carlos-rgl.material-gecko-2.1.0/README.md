# Material Gecko Theme for VS Code

Another material theme for fancy italic fonts

I love Material Theme but I miss some italics and other colours so I created this theme

![Preview](https://raw.githubusercontent.com/CarlosRGL/material-gecko-vscode/master/images/gecko1.png)

![Preview](https://raw.githubusercontent.com/CarlosRGL/material-gecko-vscode/master/images/gecko2.png)

# Installation

1. Open **Extensions** sidebar panel in VS Code. `View → Extensions`
2. Search for `Material Gecko`
3. Click **Install** to install it.
4. Click **Reload** to reload the your editor
5. Code > Preferences > Color Theme > **Material gecko**
6. Optional: Use the recommended settings below for best experience

## Recommended Settings

```js
{
  "workbench.colorTheme": "Material Gecko",
  // The Cursive font is operator Mono, it's $200 and you need to buy it to get the cursive (dank mono is cheaper also)
  "editor.fontFamily": "Operator Mono, Menlo, Monaco, 'Courier New', monospace",
  "editor.fontSize": 17,
  "editor.lineHeight": 25,
  "editor.letterSpacing": 0.5,
  "files.trimTrailingWhitespace": true,
  "editor.fontWeight": "400",
  "prettier.eslintIntegration": true,
  "editor.cursorStyle": "line",
  "editor.cursorWidth": 5,
  "editor.cursorBlinking": "solid",
  // Very important: Install this plugin: https://github.com/be5invis/vscode-custom-css
  // You'll need to change this to a file URI scheme on your computer: https://en.wikipedia.org/wiki/File_URI_scheme
  // Mac: file:///Users/YOUR-PC-USERNAME/.vscodestyles.css
  // Linux: file:///home/YOUR-PC-USERNAME/.vscodestyles.css
  // Windows: file:///C:/Users/YOUR-PC-USERNAME/.vscodestyles.css
  "vscode_custom_css.imports": [
    "file:////home/carlosrgl/.vscodestyles.css"
  ],
  "editor.renderWhitespace": "all",
}
```

## Best extension for a sweet look

1. [Bracket Pair Colorizer](https://marketplace.visualstudio.com/items?itemName=CoenraadS.bracket-pair-colorizer)
2. [Colorize](https://marketplace.visualstudio.com/items?itemName=kamikillerto.vscode-colorize)
3. [Error Lens](https://github.com/phindle/error-lens)

## Important: CSS Hacks For Extra Sweet Editor

Some things in VS Code can't be controlled by settings, but you can install [this plugin](https://github.com/be5invis/vscode-custom-css), then make a file on your computer that will hold your custom CSS, I like to make one in my root called `~/.vscodestyles.css` and then put this everything in [vscodestyles.css](https://github.com/CarlosRGL/material-gecko-vscode/blob/master/./vscodestyles.css) into your file.
Once done, open your command palette and select enable **custom CSS and JS**

Finally reload your editor and the Custom CSS should be taking.

**_Note: Reloading custom CSS and JS after every VSCode update is a must!_**

## I don't like something

First, this theme is new so if something is funky, please open an issue.

These are the things we have control over. If you would like to change something, you can either open a PR and see if I'd like it added, or override the colours in your own settings.json file.

https://code.visualstudio.com/docs/getstarted/theme-color-reference

## Thanks

Special thanks to Wesbos for the readme and ahmadawais for the emoji log and workflow
