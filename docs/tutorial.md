## Setting git to work with github Here's the tutorial I promised: 
I'll be following this guide here: [Codeberg ssh guide](https://docs.codeberg.org/security/ssh-key/), and this one for windows: [Github docs](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent?platform=windows)
0. Using Linux?  
    - Basically I suggested this because I know how to use it pretty
    well and can help you if something goes wrong or you aren't
    sure of something, whereas I'm close to clueless with windows
    (the OS you currently run). You'll need to flash firmware and
    use git/github for this project, and I know how to set it up
    with linux but not windows. If you wanted to dual boot Linux
    (another OS) on your laptop I can definitely help you with it,
    but this is kinda 'invasive' as it does involve partitioning your hard
    drive in your laptop, if you're OK with that. Then you'll select the OS in
    the boot menu. I recommend using something like Arch Linux with the
    archinstall guide and KDE plasma as the desktop, it makes it pretty easy to
    install. Make sure to install acpi and acpid, enabling acpid, for
    proper power management if it becomes weird. I can help you with
    this but only if you choose you want to. 

1. Installing the tools  
Run this in the powershell (open the windows menu, go to powershell then select run as administrator):
```powershell
winget install --id Git.Git -e --source winget
```  
Then run this to install ssh  
```pwsh
Add-WindowsCapability -Online -Name OpenSSH.Client
```
2. Generating a key
Open 'git bash' from the windows menu and run this: 
```bash
ssh-keygen -t ed25519 -C "your_email@example.com"
```
Where you replace the email with the email you used to sign up to github (your school one I think). 

3. Starting the service  
Then you need to run this to make it start and so that git can use your ssh key:

```pwsh
# start the ssh-agent in the background
Get-Service -Name ssh-agent | Set-Service -StartupType Manual
Start-Service ssh-agent
```
4. Adding the ssh key to your system
Then  
```pwsh
ssh-add c:/Users/YOU/.ssh/id_ed25519
```
Where 'YOU' is replaced by your username. You can find this by running:
```pwsh pwd```
I think. 

5. Adding the PUBLIC key to github
Then you need to give github the public key. Do this by taking the contents of the .pub key file and pasting it into the SSH and GPG keys section of settings in github in the browser. This youtube video did a pretty good job of explaining it: [How to Setup SSH for Github on Windows](https://www.youtube.com/watch?v=9gkb81GKmVI)  

6. Cloning the repo
Go back to the home page of this repo, and click on the green code button, copy the ssh url (if you don't see it then sign in), go into git bash again and run this:

```bash
git clone git@github.com:EpicBrainUser/cansat_25-6.git
```
Now you should have the code. 

7. Learning to use git
Now's probably a good time to learn to use git, as we'll be using git (the tool) a lot to collaborate on this project. Almost every software development team also uses this so it's a pretty good skill to have. I suggest you just watch a youtube video on it like this one: [Git it?](https://www.youtube.com/watch?v=HkdAHXoRtos)

8. Make a change in roadmap.md
Open up roadmap.md (the file from here) in your text editor, like VSCode or VSCodium or Zed or similar, make a change, add, commit your work and finally push it to github.  
Even better if you make a different, branch, and send in a pull request. 

Just change this: 
```md
- [ ] We both pushed to github!
```

To this:
```md
- [x] We both pushed to github!
```
