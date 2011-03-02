Tipra - Tiny printer assistant project.
=============
Set of applications written for specific needs of the customer: 
* a secure and precise monitoring of printers activity;
* lightweight and use as little system resources as possible;
* windows platform;

Environment
-------
* Qt opensource 4.7.1 with QMAKESPEC=win32-msvc2010
* MS Visual Studio 2010 Express.
* Sqlite db.
* Git
 
Before build
-------
* Install VC ("C:\Program Files\Microsoft Visual Studio 10.0") and Qt ("C:\Qt\4.7.1").
* Install git.
* Create account in the github and follow the instructions for creating a public key.
* Personalize your git in git-bash: 
		git config --global user.name "Bobby"
		git config --global user.email bobby@jmail.com
* Clone your copy of the Tipra (use git-bash):
		cd C:\MyProjects\ #Do not create folder called "Tipra" here!
		git clone git://github.com/jijaka/Tipra.git
* check all paths in Tipra/tipra.bat and run it.	
* Also: send me your public part of the ssh key, and I will give you rights to modify changes.

Build
-------	
in tipra.bat
    cd TPR_GUI
	qmake -tp vc TPR_GUI.pro
	# Here you can type nmake to build project in console.
Start VC2010 (double click on Tipra.sln) and use regular Project->Build and run.


License
-------
<p>
<a rel="license" href="http://creativecommons.org/licenses/by/3.0/"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by/3.0/80x15.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" href="http://purl.org/dc/dcmitype/InteractiveResource" property="dct:title" rel="dct:type">Tipra - tiny printer assistant</span> by <a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/jijaka" property="cc:attributionName" rel="cc:attributionURL">org.jijaka.da</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/3.0/">Creative Commons Attribution 3.0 Unported License</a>.<br />Based on a work at <a xmlns:dct="http://purl.org/dc/terms/" href="https://github.com/jijaka/Tipra" rel="dct:source">github.com</a>.
</p>