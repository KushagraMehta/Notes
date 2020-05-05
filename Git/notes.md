# *Git Directory*🗄>---<*Staged files*📁>---<*Working Tree*🌲

---

## **_Section_**

- #### [Who made What changes](#who-made-what-changes)
- #### [Starting on repository](#starting-on-repository)
- #### [Creating Snapshot of project and storing to Git directory](#creating-snapshot-of-project-and-storing-to-git-directory)

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

---

## **Basic Information\***

```git
git status
```

_Give every status/track you_

```git
git log
```

_Commit history_

`git reset --hard POINTER_ADDRESS`

`git checkout -b BRANCH_NAME` **create and we move to that new branch**

`git checkout BRANCH_NAME` **we switch to branch**

`git Branch` **this show all as well working branch**

`git merge BRANCH_NAME`**merge both branch**

`git push origin BRANCH_NAME` ()
