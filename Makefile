
installdev:
	  apt-get install -y libx11-dev libxt-dev libmotif-dev

one:
	   gcc  little-motif.c  -lXm -lXt  -o hello -lX11 


two:
	 gcc hello-motif.c   -lXm -lXt -o hello



