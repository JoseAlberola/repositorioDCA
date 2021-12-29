**********************************
|	   PRÁCTICA 9		  |
**********************************
___________________________________________________________________________

	      Sistemas de Control de Versiones de última generación
___________________________________________________________________________

	PASOS
	
	1. Creamos repositorio en GitHub
	
	2. Clonamos el repositorio
	
	3. Creamos los archivos y los metemos en el repositorio
	
	4. Creamos alias
	
		4.1. Creamos alias locales
		
			git config user.name "Jose Alberola Torres"
			git config user.email "josealberolaat@gmail.com"
		
		4.2. Cramos alias globales
		
			git config --global alias.co commit
			git config --global alias.st status
			git config --global alias.ch checkout
			git config --global alias.adgo 'log --all --decorate --graph --oneline'
		
	5. Utilizamos git bisect para encontrar el fallo
		
		5.1. Introducimos un commit con errores y hacemos un par de commits más
		
		5.2. $ git bisect start
		
		5.3. $ git bisect bad --> hemos detectado error en el commit actual 
		
		5.4. $ git adgo --> vemos el id del commit que sabemos que era correcto (0111b0d)
		
			* dd253d7 (origin/main, origin/HEAD, main) Datos autor
			* 46ffe37 Mensaje despedida
			* 16e3f9b (refs/bisect/bad) Cambio mensajes
			* 75dd98d (HEAD) Commit con error
			* 0111b0d (refs/bisect/good-0111b0d3b118a75b0263c51d2b73916070db47c2) Primeros archivos
			* d176a6c Initial commit
		
		5.5. $ git bisect good 0111b0d
		
		Biseccionando: falta 1 revisión por probar después de esta (aproximadamente 1 paso)
		[16e3f9b8de54c3af614882d8b68b334c0b20a629] Cambio mensajes
		
		5.6. Indicamos otro commit malo
			$ git bisect bad 16e3f9b
		
		5.6. Nos muestra el commit sospechoso del fallo (75dd98d)
		
		5.7. $ git bisect reset
		
	6. Arreglamos el error
	
		6.1. git diff idCommitBueno archivo
			$ git diff 0111b0d hw.c
		
		6.2. Vemos el error y lo reparamos
		
	7. Utilizamos Git Hooks
	
		HOOK para hacer un push después de hacer un commit.
		
		7.1. Creamos un archivo llamado post-commit en la carpeta .git/hooks/ del repositorio
		
		Contenido:
		
			#!/bin/sh
			git push origin main
		
		7.2. Le damos permisos $ chmod +x post-commit
 	
		7.3. Hacemos un commit y vemos que se sube automáticamente al repositorio remoto
		
		
		
