El programa se ejecuta en Windows, utilizando el compilador Mingw-w64, la version C++17 y Visual Studio Code como IDE.

El programa funciona de la siguiente manera:

1- La clase ProcesadorArchivoPersonas se encarga de procesar los archivos txt (en este caso el personas.txt)
  - se debe pasar por parametro en el constructor el nombre del archivo a procesar.
  - se utiliza el metodo CrearArchvioPersonas (donde recibe el nombre del archivo a generar por parametro) para procesar el txt, 
    en el mismo metodo utiliza la clase EscritorPersona para escribir a la persona con los datos que procesó del txt.
    
2- La clase LectorPersona se encarga de leer el archivo que procesó el Procesador
  - se debe pasar por parametro en el constructor el nombre del archivo a leer.
  - se utiliza el metodo ObtenerPersona que recibe por parametro la posicion de la persona que se desea y este retorna dicha persona.
  
  El main del programa contiene un ejemlo de como funciona el programa.
