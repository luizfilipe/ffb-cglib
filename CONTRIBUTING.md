# How to contribute

## Setup the develop environment

Follow these steps bellow to understand how to contribute.

1 - First of all, install the [git command line](http://git-scm.com/downloads).

2 - Click on the button `Fork` in the [main](http://github.com/luizfilipe/ffb-cglib.git) page of the repository, after navigate to workspace folder and clone it with the git command line below on terminal in OS X or powershell in Windows:

```git
git clone https://github.com/<your_user_name>/ffb-cglib.git
```

3 - This will upload all necessary files, making a copy of your `origin` repository with a `master branch`.

4 - Add a `upstream` repository, that is the [main](http://github.com/luizfilipe/luizfilipe/ffb-cglib.git) repository of `ffb-cglib`, for this run the line below on terminal in OS X or powershell in Windows:

```git
git remote add upstream https://github.com/luizfilipe/ffb-cglib.git
```

* Now if you run `git branch -a` you will see all remotes and local repositories like this:

```git
*master
dev
remotes/origin/master
remotes/upstream/master
```

 * The `master` is the current local branch, it is based on or an copy of the branch master of `https://github.com/<your_user_name>/ffb-cglib`. The asterisk in front of name means you are on it.

* The `dev` is a local branch for development, you have to develop here to get the up-to-date code from main `dev`, and fix issues on it, for this type `git checkout dev`. This branch is a copy of dev branch of your remote repository.

* The `remotes/origin/master` is your remote branch master, this is the properly `master` located on `https://github.com/<your_user_name>/ffb-cglib`.

* The `remotes/upstream/master`is the main remote branch `master` located on `http://github.com/luizfilipe/ffb-cglib`.

* Don't forget to make an project with the source code od the `dev` branch.

5 - To complete the setup environment, create a new project with IDE of your preference and add the source files. After exclude untracked project files from git repository adding their names in editing of `.git/info/exclude` file.

## Keep a safe flow

6 - Make sure that your repository is up-to-date with the upstream, every time that you will perform changes, for this run the command on prompt having sure that you are in the `dev` branch:

```git
git pull -r upstream dev
```

* This means you will upload all changes of other users with commits organized by datetime.

* If any conflict happens, solve the conflict with a merge tool and after type on prompt `git rebase --continue`.

## Shipping the code

7 - Make all changes that you want and when you finish, add changes to stage area with `git add -A`. After just commit the changes running the command below:

```git
git commit -m "<commit_message>"
```

**warning** if it has an commit message refering the issue with the issue number like `fix #00` the issue 00 will be automatically closed as follows in this [guide](https://help.github.com/articles/closing-issues-via-commit-messages), you have to do that but keep in mind that the issue only will be closed after an collaborator merge the code.

8 - After all this push the code against your `origin` repo. To do this, run the code below and put your credentials on the prompt:

```git
git push origin master
```

9 - Open a `pull-request` against the `dev` branch of `upstream` repository. Go to your remote GitHub repository of ffb-cglib click on the green button with the two green arrows that link one each other. If the change is not in the `dev`branch, remember to select it in main(`upstream`) repository.

10 - Wait for revision, and see the changes ships on the dev and after QA analytical work test your changes, see they going to the next stable version.