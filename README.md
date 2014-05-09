#
#
#	Tema-2 ASC
#	Ene Sebastian 333CA
#

Subpunctul 1:

	Am implementat functia "de mana" si m-am ghidat dupa
	codul pus la dispozitie in sursa din cerinta. Am corectat 
	erorile care apareau din cauza faptului ca nu erau respectati
	indicii si functionalitatea sursei nu era tocmai cea dorita.
	Erau diferente la inmultie.Apelul functiei se realizeaza printr-o
	biblioteca statica partajata in cod pe care o creeam la compilare.
	Codul se regaseste in "utils.c" iar in "utils.h" avem declaratiile
	functiilor folosite.
	Biblioteca se compileaza pt fiecare apel al comenzii: "make all".
	Stergerea se face automat prin intermediul comenzii "make clean".
	Prima data m-am gandit la compilarea fisierului scris in fortran
	si apelul functiei direct de acolo dar necesita niste dependente
	suplimentare.

Subiectul 2:

	Am linkeditat cu biblioteca pusa la dispozitie de pe cluster
	si am inclus la compilare path-ul catre header-ul folosit.
	Am descoperit in urma unui apel "module available" rulat
	pe cluster toate modulele de care aveam nevoie in Makefile
	,iar acestea sunt:

	libraries/atlas-3.10.1-gcc-4.4.6-nehalem
	libraries/atlas-3.10.1-gcc-4.4.6-opteron
	libraries/atlas-3.10.1-gcc-4.4.6-quad

Subiectul 3:
	
	Pentru verificare se apeleaza scriptul run.sh pe cluster
	si se asteapta submiterea de job-uri.Rezultatele sunt
	printate in folder-ul out/.		
	In urma rularii cu diferite dimensiuni ale matricii
	generata aleator data la input am obtinut urmatorii
	timpi de executie iar diferentele sunt evidente:
	Mentionez ca testele le-am facut pe o matrice generata aleator
	superior triunghiulara cu numarul de elemente de 25000, 20000, 
	15000, 10000, 5000 iar cateva din datele obtinute aici sunt:

	****************************************************************
	quad:
	[CBLAS_neoptimizat]nr elemente:[20000] calculul dureaza:1.673196
	[CBLAS_atlas_cblas]nr elemente:[20000] calculul dureaza:0.462151

	nehalem:
	[CBLAS_neoptimizat]nr elemente:[20000] calculul dureaza:1.117547
	[CBLAS_atlas_cblas]nr elemente:[20000] calculul dureaza:0.167842

	opteron:
	[CBLAS_neoptimizat]nr elemente:[20000] calculul dureaza:1.620595
	[CBLAS_atlas_cblas]nr elemente:[20000] calculul dureaza:0.261547

	****************************************************************
	quad:
	[CBLAS_neoptimizat]nr elemente:[10000] calculul dureaza:0.422232
	[CBLAS_atlas_cblas]nr elemente:[10000] calculul dureaza:0.133619

	nehalem:
	[CBLAS_neoptimizat]nr elemente:[10000] calculul dureaza:0.278863
	[CBLAS_atlas_cblas]nr elemente:[10000] calculul dureaza:0.043742

	opteron:
	[CBLAS_neoptimizat]nr elemente:[10000] calculul dureaza:0.621213
	[CBLAS_atlas_cblas]nr elemente:[10000] calculul dureaza:0.066026

	Graficele corespunzatoare sunt in directorul "graf" din radacina
	Am generat graficele cu ajutorul datelor obtinute din directorul
	"data" pe baza scriptului "gnuplot_script.sh" pe care l-am rulat
	pentru fiecare arhitectura in parte.
	Rezultatele arata o diferenta imensa intre timpul computational
	al functiei "de mana" fata de timpul rularii functiei optimizate 
	din atlas.La o prima vedere se poate observa ca testul de pe Nehalem
	al functiei cblas_dtrmv(Atlas)cu 20 de mii de elemente obtine
	rezultatele cele mai bune, dupa aceea Opteron si ultimul fiind clasat 
	Quad-ul.
	Pentru functia implementata de mana rezultatele cele mai bune sunt in 
	aceiasi ordine, observam o panta apropae exponentiala a graficului.

Subiectul 4:
	Optimizare cu flaguri de compilare(-O2 -O3)
	Optimizare pe care am abordat-o consta in paralelizarea cu 
	thread-uri a algoritmului de inmultire utilizand POSSIX THREADS,
	utilizarea registrelor pentru a elimina accesul intensiv la 
	memorie.
		

