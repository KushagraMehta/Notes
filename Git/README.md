# *Git Directory*🗄>---<*Staged files*📁>---<*Working Tree*🌲

---

## **_Section_**

- #### [Who made What changes](#who-made-what-changes)
- #### [Starting on repository](#starting-on-repository)
- #### [Creating Snapshot of project and storing to Git directory](#creating-snapshot-of-project-and-storing-to-git-directory)
- #### [Creating Snapshot of project and storing to Git directory](#Creating-Snapshot-of-project-and-storing-to-Git-directory)
- #### [Basic Information](#Basic-Information)
- #### [To Modify Files](#To-Modify-Files)
- #### [Undoing Things](#Undoing-Things)
- #### [Branching and Merging](#Branching-and-Merging)
- #### [Working on Remote Repository](#Working-on-Remote-Repository)
- #### [.gitignore files](#.gitignore-files)

---

## **Git commit message Convention**

> **Short summary** _upto 50 characters_
>
> **Long Discription** _upto 72 characters_

<pre>
Commit message style guide for Git

The first line of a commit message serves as a summary. When displayed
on the web, it's often styled as a heading, and in emails, it's
typically used as the subject. As such, you should capitalize it and
omit any trailing punctuation. Aim for about 50 characters, give or
take, otherwise it may be painfully truncated in some contexts. Write
it, along with the rest of your message, in the imperative tense: "Fix
bug" and not "Fixed bug" or "Fixes bug". Consistent wording makes it
easier to mentally process a list of commits.

Oftentimes a subject by itself is sufficient. When it's not, add a
blank line (this is important) followed by one or more paragraphs hard
wrapped to 72 characters. Git is strongly opinionated that the author
is responsible for line breaks; if you omit them, command line tooling
will show it as one extremely long unwrapped line. Fortunately, most
text editors are capable of automating this.
</pre>

---

## **Who made what changes**

[git config](https://git-scm.com/docs/git-config#_description) : _Configure user information for local repositories_

```git
git config --global user.email "me@example.com"
```

```git
git config --global user.name "My name"
```

```git
git config -l
```

_To know configuration of the repo_

---

## **Starting on repository**

```git
git init
```

_Every time we made file_

```git
git add "file_name" | get add .
```

_Add file new as well as modified files to staging area so that git can track it_

---

## **Creating Snapshot of project and storing to Git directory**

```git
git commit -m "can write your message"
```

_Only commit files which are add to current staging area & are modified_

- [`-a`](https://git-scm.com/docs/git-commit#Documentation/git-commit.txt--a) : _A shortcut to stage any changes to tracked files and commit them in one step.(`not work on new files`)_
- [`-p`](https://git-scm.com/docs/git-commit#Documentation/git-commit.txt--p) : _To know the diffrence made in files from last commit. And we want to stage them or not._
- [`--amend`](https://git-scm.com/docs/git-commit#Documentation/git-commit.txt---amend) :_To amended our previous commit. As it rewrites the git history removing the previous commit and replacing it with the amended one._

---

## **Basic Information**

```git
git status
```

_Give every status/track you_

```git
git diff
```

_To know the diffrence made in files from last commit for unstaged files.(For particular file pass its name as parameter)_

- [`--staged`](https://git-scm.com/docs/git-diff#Documentation/git-diff.txt-emgitdiffemltoptionsgt--cachedltcommitgt--ltpathgt82308203) : _To see the changes which are staged but not commited._

```git
git log
```

_Commit history_

**Flag**

- [`-p`](https://git-scm.com/docs/git-log#Documentation/git-log.txt--p) : _Commit history with patch._
- [`--stat`](https://git-scm.com/docs/git-log#Documentation/git-log.txt---statltwidthgtltname-widthgtltcountgt): Which files were changed and how many lines were added or removed.

```git
git show COMMIT-ID
```

_Patches of particular commit._

---

## **To Modify Files**

```git
git rm FILE-NAME
```

```git
git mv FILE-NAME NEW-NAME
```

---

## **Undoing Things**

`git checkout <file_name>` : restore working tree files(only talking in reference to Undoing).

`git revert HEAD` : It will kept our history record & make new commit by reversing the effect of some earlier commits.

`git reset` : Reset current HEAD to the specified state or to remove file from stagging area.

- [`--soft`](https://git-scm.com/docs/git-reset#Documentation/git-reset.txt---soft) : _Reset HEAD But keeping the changed file in the staging area._
- [`--mixed`](https://git-scm.com/docs/git-reset#Documentation/git-reset.txt---mixed) : **default** _Same as --soft but changes are not in staging area but are in working area._
- [`--hard`](https://git-scm.com/docs/git-reset#Documentation/git-reset.txt---hard) : _It will make thw working directory as it was during that commit(only for tracked files, For untracked file use `git clean -df`)._
  - [`git reflog`](https://git-scm.com/docs/git-reflog) : _To correct accidental reset to some extend before the garbage cleanup._

---

## **Branching and Merging**

`git branch <BRANCH-NAME>` : Create new branch was created based on the value of head(Branch is a pointer to a sequence of commit).

- [`-d`](https://git-scm.com/docs/git-branch#Documentation/git-branch.txt--d) : To delete branch.

> `git checkout -b <BRANCH-NAME>` : Create new branch as well as switch to it.

`git merge <BRANCH-NAME>` : _Merge data of < BRANCH-NAME> with current working branch._

`git log --graph --oneline` : This shows a summarized view of the commit history for a repo.

---

## **Working on Remote Repository**

> Whenever we're operating with remotes, Git uses remote branches to keep copies of the data that's stored in the remote repository. We could have a look at the remote branches that our Git repo is currently tracking by running git branch -r. These branches(origin/master) are read only. We can look at the commit history, like we would with local branches, but we can't make any changes to them directly. To modify their contents, First, we pull any new changes to our local branch, then merge them with our changes and push our changes to the repo.

`git remote show origin` : information about remote repo.

`git fetch` : Copies the commits done in the remote repository to the remote branches.

- `git merge origin/master` : To merge change with master branch.

`git pull` : Copies the commits done in the remote repository and merge with master branch.

`git push <remote> <branch>` : It is used to upload local repository content to a remote repository.

- `--delete` : To delete branch from remote repository.

`git rebase <branch>` : It will integrates changes from one branch into another.

| Rebase                                                            | Merge                                        |
| ----------------------------------------------------------------- | -------------------------------------------- |
| Moves the entire branch to begin on the tip of the another branch | Is a non-destructive operation               |
| Re-writes the project history                                     | Existing branches are not changed in any way |
| We get much cleaner and linear project history                    | Creates a new merge commit in the branch     |

---

## [**.gitignore files**](https://git-scm.com/docs/gitignore)

.gitignore files are used to tell the git tool to intentionally ignore some files in a given Git repository. For example, this can be useful for configuration files or metadata files that a user may not want to check into the master branch.

---
