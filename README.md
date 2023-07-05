# SistemaGestionDeVentas
INTRODUCCION: 
Este sistema, permite gestionar las distintas ventas de la librería, cuenta con un login de usuario, con tres módulos, módulo de venta, modulo usuario, y modulo stock; Su interfaz grafica en por consola, que cuenta con un menú principal, donde mediante el uso de las opciones puedo ingresar a los distintos módulos.
DESCRIPCION DEL SISTEMA:  
Para comenzar, el sistema tiene un “login” de usuario, en el cual los usuarios tienen diferentes roles, uno es el de vendedor y el otro de administrador, estos tienen distintos permisos donde el administrador es el que cuenta con todos los permisos. En el caso que esté en rol de vendedor, y quiera realizar una acción, la cual solo tiene permiso el administrador, me va a pedir que me identifique como administrador para poder realizarlo.
Este sistema cuenta con un menú principal donde, mediante distintas opciones, puedo ingresar a los distintos módulos.
El modulo de venta, tenemos la opción de cargar una venta, al cargar la venta nos va a pedir el id del libro que quiero vender, (es el primer dato ya que hay que validar si existe el libro) en el caso de no existir el sistema me avisara con un mensaje por pantalla, lo mismo ocurre con la cantidad vendida, que hará una consulta al archivo de stock, para validar la cantidad, si no hay la cantidad pedida, lo avisara por pantalla. Una vez que realice estas validaciones me pedirá, fecha de la compra, y los datos del cliente: el primer dato que me pedira sera el dni, para validar si ya se encuentra en nuestros registros ese cliente, validamos, y si se encuentra no os pedira ningun dato de cliente, pero no lo encuentra se tendrán que cargar esos datos; el importe se autogenera haciendo una consulta del valor al archivo de libros por id de libro, por la cantidad vendida. El id de la venta se autogenera también. Una vez cargada la venta, nos preguntará por pantalla si hay otro producto para vender, en el caso de ser positivo nos pedirá nuevamente los datos, y en caso de ser la respuesta negativa, se finaliza la carga de la venta.
 Por último, podremos eliminar una venta por cualquier tipo de problema con esta. (esta acción necesita permiso del administrador). 
Una vez registrada la venta, generará una factura para el cliente que se guardará en un archivo de facturas. 
En el módulo de stock, podremos cargar un nuevo libro, donde nos pedirá el nombre del libro autor, precio, género del libro(del 1 al 5) y la cantidad de stock. También, está la opción de modificar el stock, que la usaremos cuando queramos sumar stock a un libro determinado (acción que solo puede realizar el administrador). En este módulo también podremos ver el stock mediante distintos listados, por ejemplo, stock de todos los libros, o, el stock de un determinado libro realizando una búsqueda por id de libro. También podremos eliminar un libro por baja lógica (esta acción también solo la podrá realizar el administrador). 
En el módulo de usuarios, podremos crear usuarios, tanto como vendedores como administradores, para esta acción nos pedirá nombre, apellido y dni, y crear un nombre de usuario y contraseña. Los usuarios administradores solo se pueden crear si el usuario se identificó como tal. También se puede eliminar los usuarios (solo lo puede realizar el administrador), modificar usuarios (nombre de usuario, o contraseña), y listar los distintos usuarios. 

SALIDA POR PANTALLA:
El sistema tendrá tres tipos de salidas, listado, informe y consulta.

LISTADOS: 

Listado de ventas:
-Listar todas las ventas ordenadas por fecha. 

Listado de usuario: 
-Listar todos los usuarios.

Listado stock: 
-Listado de todos los libros


 CONSULTAS:  

Consultas de usuario: 
-Por nombre de usuario. 
-Por rol de usuario. 

Consultas ventas: 
-Por id de libro. 
-Por fecha e id de libro.
-Por id de venta. 

Consulta stock: 
-Por id de libro.
-Por autor. 

INFORMES:


Informe de usuario: 
-Recaudación de un usuario mensual. 
-Recaudación anual por usuario. 

Informes stock: 
-Recaudación de un libro específico mensual y total. 
-Recaudación mensual y total por autor.
-Recaudación mensual y total por género.

Informe Ventas: 
-Total, facturado por mes.
-Total, facturado anual. 
-Ranking de los 10 más vendidos.
-Ranking de los 10 más vendidos por género.

Tambien permite imprimir un recibo de venta, con los subtotales y con el importe total, en este recibo se detallan tambien los nombre de los libros la cantidad, fecha y tambien los datos del comprador.
Este archivo que se genera es un archivo de texto plano. no es binario, por lo tanto se puede ver su contenido con cualquier editor de texto.
