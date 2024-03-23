**_LeetCode to GitHub Extension_**

**Description**
This Chrome extension automatically synchronizes your LeetCode submissions to a designated GitHub repository. Whether you're solving daily challenges, preparing for interviews, or just practicing coding problems, this extension ensures your progress is tracked and showcased on GitHub. It's perfect for developers who want to maintain a clean record of their problem-solving journey, share their solutions with others, or keep a backup of their work.

**Features**
Automatic Sync: Every time you submit a solution on LeetCode, the extension pushes it to your GitHub repository.
Customizable Commit Messages: Customize the format of your GitHub commit messages.
Support for Multiple Languages: Whether your solution is in Python, JavaScript, Java, or any other language supported by LeetCode, the extension handles it smoothly.
Privacy-Focused: Choose which submissions (Accepted, Wrong Answer, etc.) to sync.
Easy Setup: With a straightforward setup process, you can start syncing your solutions in no time.

**Installation**
Clone this repository or download the ZIP file.
Navigate to chrome://extensions in your Chrome browser and enable "Developer mode" at the top right.
Click on "Load unpacked" and select the directory where you've cloned or unzipped the extension.
Once added, you'll see the extension icon in your browser's toolbar.

**Configuration**
Before using the extension, you need to configure it with your GitHub token and specify the repository where you'd like your submissions to be posted.

Generate a new GitHub token (Settings > Developer settings > Personal access tokens > Generate new token) with the repo scope.
In the extension's options page, enter the generated GitHub token and the name of your repository (in the format username/repository).
(Optional) Customize your commit message format and select which types of submissions to sync.

**Usage**
Once configured, the extension works automatically. Simply solve problems on LeetCode, and upon submission, your solutions will be committed to the specified GitHub repository. Check your repository to see your updated solutions.
