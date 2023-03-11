### Hi there 👋

<!--
**Shnku/Shnku** is a ✨ _special_ ✨ repository because its `README.md` (this file) appears on your GitHub profile.

Here are some ideas to get you started:

- 🔭 I’m currently working on ...
- 🌱 I’m currently learning ...
- 👯 I’m looking to collaborate on ...
- 🤔 I’m looking for help with ...
- 💬 Ask me about ...
- 📫 How to reach me: ...
- 😄 Pronouns: ...
- ⚡ Fun fact: ...
-->
To publish to GitHub

    Your terminal should read:

    gitpod /workspace/repo-name

    Next type:

    git status

    It will respond with a list of files that have been added since the last commit. (See Screenshot below)
    Next add the new files using:

    git add --all or git add *

    This command stages the files for publishing.
    Confirm the files were added using:

    git status 

    (See Screenshot below)
    To commit changes type

    git commit -m "Description of Changes in this commit" 

    This will commit changes and add a description to the commit version. When you submit assignments please include that this is an assignment submission. For example, When. you submit your first HTML Assignment make sure to indicate that in the notes “Prototype HTML Assignment Submission”
    Now to push the changes to Github run:

    git push 

    Check your Github Pages URL and you should see the file you just uploaded. (https://thomaswallace.github.io/it-topaz/)
    #problem
    $ git push origin main
> To https://github.com/USERNAME/REPOSITORY.git
>  ! [rejected]        main -> main (non-fast-forward)
> error: failed to push some refs to 'https://github.com/USERNAME/REPOSITORY.git'
> To prevent you from losing history, non-fast-forward updates were rejected
> Merge the remote changes (e.g. 'git pull') before pushing again.  See the
> 'Note about fast-forwards' section of 'git push --help' for details.

You can fix this by fetching and merging the changes made on the remote branch with the changes that you have made locally:

```$ git fetch origin```
> Fetches updates made to an online repository
```$ git merge origin YOUR_BRANCH_NAME```
> Merges updates made online with your local work

Or, you can simply use git pull to perform both commands at once:

```$ git pull origin YOUR_BRANCH_NAME```
> Grabs online updates and merges them with your local wor

