-- tabla de las localidades gestionadas en el sistema
create table localidad(
	cod_postal int primary key, 
	nombre varchar(60)
);
-- tabla de pais
create table pais(
	codigo serial primary key, 
	nombre varchar(60)
);
-- tabla para mantener las formas de pago
create table forma_pago(
	codigo serial primary key, 
	forma varchar(50)
);
-- agencia que ofrece el paquete
create table agencia
(
  codigo serial NOT NULL primary key,
  nombre varchar(90),
  calle varchar(150),
  nro varchar(7),
  piso varchar(7),  
  dpto integer,  
  codigo_postal integer,
  telefono1 varchar(20),
  telefono2 varchar(20)
);
alter table agencia add constraint fk_agencia_localidad foreign key(codigo_postal) references localidad(cod_postal);
-- turista que adquiere el paquete
create table turista
(
  dni integer primary key,
  nombre varchar(90),
  domicilio varchar(150),  
  telefono varchar(50),  
  cod_pais int  
);
alter table turista add constraint fk_turista_pais foreign key(cod_pais) references pais(codigo);
--- plantilla del paquete que se puede ofrecer, una vez solicitado por un turista ya es un paquete consolidado
create table tipo_paquete
(
  codigo serial NOT NULL primary key,
  nombre varchar(60),
  descripcion varchar(250),
  duracion timestamp,
  nivel int -- especifica la dificultad del paquete -- 1: facil : 2:dificil 3 : extremo
);
-- tabla que mantiene los tipos de paquetes que provee la agencia, para listar en la carga de informacion de paquetes disponibles por agencia.
create table agencia_tipo_paquete
(
	cod_agencia int,
	cod_tipo_paquete integer
);
alter table agencia_tipo_paquete add constraint fk_Agencia_TipoPaquete_Agencia foreign key(cod_agencia) references agencia(codigo);
alter table agencia_tipo_paquete add constraint fk_Agencia_TipoPaquete_Tp_Paq foreign key(cod_tipo_paquete) references tipo_paquete(codigo);
alter table agencia_tipo_paquete add constraint pk_Agencia_TipoPaquete primary key(cod_agencia,cod_tipo_paquete);

-- tipos de actividades
create table tipo_actividad
(
  codigo serial NOT NULL primary key,
  nombre varchar(60),
  descripcion varchar(250),
  duracion time ,
  nivel int -- especifica la dificultad del  tipo de actividad   -- 1:facil 2:c/dificultad baja 3:c/dificultad media 4:c/dificultad alta 5:extremo
);
-- plantilla delo que puede contener el tipo de paquete tipos de actividades
create table tipo_paquete_tipo_actividad
(
  cod_tipo_paquete integer,
  cod_tipo_actividad integer  
);
alter table tipo_paquete_tipo_actividad add constraint fk_TipPaquete_TipoActividad_TPaquete foreign key(cod_tipo_paquete) references tipo_paquete(codigo);
alter table tipo_paquete_tipo_actividad add constraint fk_TipPaquete_TipoActividad_TActividad foreign key(cod_tipo_actividad) references tipo_actividad(codigo);
alter table tipo_paquete_tipo_actividad add constraint pk_TipPaquete_TipoActividad primary key(cod_tipo_paquete,cod_tipo_actividad);

create table transporte
(
	codigo serial primary key,
	dominio varchar(15), --identificacion del vehiculo
	descripcion varchar(150), --se detalla colectivo, capacidad, modelo...etc
	importe float
);
-- actividad que se genera del tipo de actividad, donde se especifica el importe
create table actividad
(
  codigo serial NOT NULL primary key,
  cod_tipo_actividad int,  
  cod_transporte int,  
  importe float,
  nivel int  -- especifica la dificultad de la actividad proviene de "tipo_actividad"
);	   
alter table actividad  add constraint fk_actividad_tipo_actividad foreign key(cod_tipo_actividad) references tipo_actividad(codigo);
alter table actividad  add constraint fk_actividad_transporte foreign key(cod_transporte) references transporte(codigo);
-- paquetes concretos creados para un turista que los adquiere, de una agencia dada
create table paquete
(
  codigo serial NOT NULL primary key,
  cod_tipo_paquete int,
  cod_agencia int,
  fecha date,  
  dni_turista int,
  nivel int -- especifica la dificultad de la actividad proviene de "tipo_paquete" 
  
);
alter table paquete add constraint fk_paquete_tipo_paquete foreign key(cod_tipo_paquete) references tipo_paquete(codigo);
alter table paquete add constraint fk_paquete_tipo_turista foreign key(dni_turista) references turista(dni);
-- conjunto de actividades del paquete adquirido de una agencia por parte de un turista
create table paquete_actividad
(
  cod_paquete integer,
  cod_actividad integer,
  importe float,
  fecha_hora_desde timestamp,
  fecha_hora_hasta timestamp,
  detalle varchar(120)  
);
alter table paquete_actividad add constraint fk_paquete_actividad_paquete foreign key(cod_paquete) references paquete(codigo);
alter table paquete_actividad add constraint fk_paquete_actividad_actividad foreign key(cod_actividad) references actividad(codigo);
alter table paquete_actividad add constraint pk_paquete_actividad primary key(cod_paquete,cod_actividad);

-- factura del paquete del turista
create table factura_turista
(
	nro int,
	serie int,
	letra varchar(1),
	fecha date,
	dni_turista int,
	cod_forma_pago int,
	det_pago varchar(90)
);
alter table factura_turista add constraint pk_factura primary key(nro, serie, letra);
alter table factura_turista add constraint fk_factura_forma_pago foreign key(cod_forma_pago) references forma_pago(codigo);
alter table factura_turista add constraint fk_factura_turista foreign key(dni_turista) references turista(dni);
-- detalle de la factura del turista
create table det_factura_turista
(
	nro_fact int,
	serie_fact int,
	letra_fact varchar(1),
	nro_renglon int,
	cod_paquete int,
	importe float
);
alter table det_factura_turista add constraint fk_det_factura_turista_factura_turista foreign key(nro_fact, serie_fact, letra_fact) references factura_turista(nro, serie, letra);
alter table det_factura_turista add constraint fk_det_factura_turista_paquete foreign key(cod_paquete) references paquete(codigo);
alter table det_factura_turista add constraint pk_det_factura_turista primary key(nro_fact, serie_fact, letra_fact);
/*

Los Objetos del dominio de aplicacion son

	- Localidad
	- Agencia
	- Transporte
	- Forma de Pago
	- Tipo de Paquete
	- Agencia Tipo Paquetes que ofrece.
	- Tipo de Actividad
	- Tipo de actividad de Tipo de Paquete: Plantilla para conformar paquetes especificos a turistas.
	- Actividades
	- Paquetes	
	- Actividades de Paquetes: armado desde la plantilla
	- Pais
	- Turistas
	- Factura
	- Detalle de Factura
	
*/
-- insercion de datos en algunas tablas base.
insert into localidad(cod_postal, nombre) values(9100,'Trelew'),(9103,'Rawson'),(9120,'Puerto Madryn');

insert into forma_pago(codigo,forma) values(1,'Efectivo'),(2,'Debito Maestro'),(3,'Debito Visa'),(4,'Tarjeta Cred Visa');

insert into pais(codigo,nombre) values(1,'Argentina'),(2,'Brasil'),(3,'Uruguay'),(4,'Chile'),(5,'Colombia');

