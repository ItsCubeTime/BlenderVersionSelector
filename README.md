# Blender Version Selector
Blender version selector automatically picks the correct Blender version when you double-click a .blend file based on which version of Blender the file was last saved in!

Essentially this is useful for anyone that frequently use different versions of Blender on the same computer & for different projects. For my particular usecase I originally developed this as I use one Blender version for my Armory 3D projects and another more recent version for other projects as I tend to love using alpha/beta releases (of which Armory typically doesnt support).

If the version selector fails to find a version on your system that matches the version of which the blend file was last saved in, it will prompt you which version you wanna use instead :)

For the time being its Windows only, though it might be relatively easy to port considering the entire application is under 300 lines of code.

# Blender Artists thread:

https://blenderartists.org/t/blender-version-selector/1311866/2

# Demo video

https://vimeo.com/566190901

# How it works

![image](https://user-images.githubusercontent.com/20190653/123626919-a5a48b80-d811-11eb-8f5f-8b08037bc0f5.png)

# Setup

* Once you got the binary ready you will have to add the following to your registry like so:
![image](https://user-images.githubusercontent.com/20190653/122966451-a361ad80-d389-11eb-86da-a7b069f0ac2e.png)
This adds "main.exe" to Windows "open with" menu.

* Next up you will need to configure Windows to open up the version selector when you attempt opening any blend file:
1. ![image](https://user-images.githubusercontent.com/20190653/122966699-e885df80-d389-11eb-95e6-fb0bf6578565.png)
2. ![image](https://user-images.githubusercontent.com/20190653/122966821-110dd980-d38a-11eb-86f0-261c5994490f.png)
3. Navigate to the version selector execuatable.

* Lastly you will need to open up the settings.json and replace the templated info with whats relative for your system. Essentially what youre doing here is writing out your Blender versions that you have installed and tell the version selector the path to there install directory (the directory that the Blender executable lives in). Note that version selector assumes the executable to be called "blender.exe". The settings.json goes in the same folder as your version selector executable!

* And now you should be all set! If you run into any problems, please do open an issue or discussion here on Github ( https://github.com/ItsCubeTime/BlenderVersionSelector/ ).

# Contact

My Discord ( @ItsCubeTime ) : danieljackson#0286

I get notified otherwise if you open a discussion or issue here on Github :) Its up to you how you wanna contact me.

# Contributing

Anyone is welcome to contribute, simply open a PR with your suggested changes and I will merge it soon after. If you want to discuss any code changes or implementation of features beforehand, open an issue or discussion or send me a DM over Discord

# Compiling

Compiles with cl.exe directly from the cmd line like so: 
```cl main.cpp -o main -Zi```.
cl.exe is a part of MVSC and comes installed with Visual Studio or Visual Studio Build Tools. The `-Zi` flag includes debugging symbols, so its optional if you're not planning to run a debugger on it.

See: https://docs.microsoft.com/en-us/cpp/build/reference/compiler-options?view=msvc-160 , https://docs.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=vs-2019
