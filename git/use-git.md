# git notes
主要通过git小游戏来学习git的使用，链接 https://learngitbranching.js.org/?locale=zh_CN
## git常用命令
| 命令名称     | 作用| 
|:------------|---------:|
| git config --global user.name 用户名  | 设计用户签名|
| git config --global user.email 邮箱  | 设计用户签名|
| git init  | 初始化本地库|
| git status | 查看本地库状态|
| git add 文件名 | 添加到暂存区|
| git commmit -m "log" 文件名 | 提交到本地库|
| git branch <分支名> | 创建新分支|
| git checkout <分支名> | 切换分支|
| **git reflog** | 查看历史记录|
| **git reset --hard 版本号** | 版本穿梭|

下面按照小游戏中指令循循渐进进行学习
## 基础篇
git commit  
git branch  
### 合并分支 merge rebase
#### git merge
合并分支，如在main分支合并bugFix分支，就是git merge bugFix 最后是在main分支
#### git rebase
让提交记录更线性 ,Rebase 实际上就是取出一系列的提交记录，“复制”它们，然后在另外一个地方逐个的放下去  
for example,我们现在在其他分支bugFix，想移到main分支  
1. git rebase main
2. 切换到main更新main分支 `git checkout main` 、`git rebase bugFix`

## 高级篇
### 分支移动
1. 先了解HEAD，**HEAD是当前分支的符号引用，也就是当前分支最近一次提交记录**，***通常HEAD指向分支名，分支名指向提交记录***  
    需要分离HEAD，使HEAD指向提交记录  `git checkout c1` 
c1代表某个提交记录的哈希值,一般用git log 查看提交记录，即哈希值。  

    HEAD指向提交记录，即为 **HEAD分离状态**

2. 由于查看哈希值比较麻烦，所以引出相对引用  
**^ 向上移动一个记录，~num 向上移动 num个记录**  
如``git checkout HEAD^`` 就会移动到上上次提交记录
等同于 ``git checkout HEAD~2``  

    >相对引用通常用来移动分支，如``git branch -f HEAD~3``  
    >**main 分支强制指向 HEAD 的第 3 级 parent 提交**。
### 撤销分支
主要通过reset 和 revert
#### git reset
git reset 改写历史，之后历史记录不再存在，如 git reset HEAD^,通常使用在本地分支，但对 远程分支 无效
#### git revert
撤销提交 ``git revert HEAD  ==  git reset HEAD^``,两者等同，只是revert适合远程库一点

## 远程分享代码篇
前面都是讲本地的，这里讲怎么进行代码提交，代码拉取之类的
### git clone
clone之后，本地会多一个 origin/main 分支，就是远程分支，一般都是本地新建一个分支如binyun，将binyun的更改push到 origin/main,远程仓库会自动更新。
### git fetch
git fetch 从远程仓库获取数据，远程分支也会相对于更新，就是类似于下载操作。
### git pull
git pull 就是拉取数据，就是 git fetch 和 git merge 合并起来，将所有更新，更新到本地binyun分支
### 案例
1. 你基于v1改的代码，但是现在远程是v2，不能直接git push  
    1. `git pull --rebase` then  `git push`,意味着 fetch rebase 和 push
    2. `git pull ` then  `git push`,意味着 fetch merge 和 push
2. 通常远程仓库main分支都不让直接合并的，要建个自己的分支
    所以一般先git clone 然后 git checkout -b binyun，再git push origin binyun， 这样远程仓库有一个自己的分支了，就可以随意push。  
    binyun是自己建立的分支名
3. 更复杂的工作流  
   1. 远程有更改，本地有 side1 side2 side3 三个更改，`git getch 、git rebase o/main side1 、git rebase side1 side2、git rebase side2 side3、git rebase side3 main、git push` 

### 远程
git push是先将工作从 main 推到远程仓库中的 main 分支(同时会更新远程分支 o/main)，git pull是先下载到o/main，然后更新到main
1. 怎么建立跟踪  
   1. git checkout -b binyun o/main 新建binyun分支，跟踪远程分支
   2. git branch -u o/main binyun，如果就在binyun分支上可以直接省略binyun
2. git push origin main，将本地main分支推送到远程仓库
3. git push origin source:destination  这是指定本地分支和远程分支，如果远程不存在，就会自动帮你创建 

## 进阶篇
### git cherry-pick 
将一些版本号复制到当前所在位置下面  
如``git cherry-pick c1 c2``
### git rebase -i 
交互式rebase，将特定的版本号复制过来，这个会显示一些哈希值


   to be continued 。。。后续有需要继续学习  
   binyun 2024.3.27


















