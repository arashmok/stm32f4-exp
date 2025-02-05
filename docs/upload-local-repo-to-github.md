# Uploading a Local Folder to an Existing GitHub Repository

This guide will help you take a local folder on your computer, initialize it as a Git repository, and link it to an **existing empty GitHub repository**.

---

## 1. Open Your Local Folder in VS Code
1. **Open VS Code**.
2. Go to **File > Open Folder**, then choose the folder you want to upload.

---

## 2. Initialize Git in Your Folder
Open the **Terminal** in VS Code (`View > Terminal`) and run:

```bash
 git init
```

This will initialize a new Git repository inside your folder.

---

## 3. Create a `.gitignore` File (Optional but Recommended)
To avoid committing unnecessary files, create a `.gitignore` file and add the following lines (adjust based on your project needs):

```gitignore
*.bin
*.o
build/
*.log
.env
```

Save the file before proceeding.

---

## 4. Stage and Commit Your Files
Run the following commands to track and save your changes:

```bash
 git add .
 git commit -m "Initial commit"
```

---

## 5. Link Your Local Repo to GitHub
1. **Go to GitHub** and navigate to the **empty repository** you created.
2. Copy the **HTTPS** or **SSH** repository URL.
3. In VS Code's terminal, run:

```bash
git remote add origin <YOUR-REPO-URL>
```

Replace `<YOUR-REPO-URL>` with the actual repository URL.

---

## 6. Push Your Code to GitHub
Run the following command to upload your code:

```bash
git push -u origin main
```

> **Note:** If your repository uses `master` instead of `main`, replace `main` with `master`.

---

## 7. Verify the Upload
1. Refresh your **GitHub repository** page.
2. Your files should now be visible.
3. Your repository is now connected to GitHub!

---

## Troubleshooting

- **“fatal: not a git repository”** → Ensure you have run `git init` in the correct directory.
- **Authentication Issues** → Ensure GitHub authentication is set up correctly.
- **Wrong Branch Name** → Adjust the branch name (`main` vs. `master`) in your push command.

---
