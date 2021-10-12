-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Versión del servidor:         8.0.20 - MySQL Community Server - GPL
-- SO del servidor:              Win64
-- HeidiSQL Versión:             11.0.0.5919
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Volcando estructura de base de datos para tienda_electronica
CREATE DATABASE IF NOT EXISTS `tienda_electronica` /*!40100 DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `tienda_electronica`;

-- Volcando estructura para tabla tienda_electronica.cliente
CREATE TABLE IF NOT EXISTS `cliente` (
  `Codigo` int NOT NULL,
  `Nombre_Cliente` varchar(25) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `Estado` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT 'A',
  `Direccion` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `Telefono` varchar(15) COLLATE utf8_unicode_ci NOT NULL,
  `Email` varchar(25) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`Codigo`),
  UNIQUE KEY `Nombre_Cliente` (`Nombre_Cliente`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Volcando datos para la tabla tienda_electronica.cliente: ~8 rows (aproximadamente)
/*!40000 ALTER TABLE `cliente` DISABLE KEYS */;
INSERT IGNORE INTO `cliente` (`Codigo`, `Nombre_Cliente`, `Estado`, `Direccion`, `Telefono`, `Email`) VALUES
	(1, 'PACHECO', 'A', 'FISHERMAN', '3256987465', 'pacheco@gmail.com'),
	(2, 'DAVID', 'A', 'SIEMPREVIVA', '7895462138', 'david@gmail.com'),
	(3, 'CESAR', 'A', 'BOULEVARD', '5468973215', 'cesar@gmail.com'),
	(4, 'ULISES', 'A', 'OLIMPICA', '2136549865', 'ulises@gmail.com'),
	(5, 'EDGAR', 'A', 'REVOLUCION', '1488965723', 'edgar@gmail.com'),
	(6, 'JOSE', 'A', 'INDEPENDENCIA', '5646889765', 'jose@gmail.com'),
	(7, 'PIMENTEL', 'A', 'FEDERALISMO', '2236547895', 'pimentel@gmail.com'),
	(8, 'STEVEN', 'A', 'LA PAZ', '6653214896', 'steven@gmail.com');
/*!40000 ALTER TABLE `cliente` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.detalle
CREATE TABLE IF NOT EXISTS `detalle` (
  `ID_Detalle` int NOT NULL,
  `Cod_Barras` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `Cantidad` int NOT NULL,
  `Sub_Total` double NOT NULL,
  KEY `ID_Detalle` (`ID_Detalle`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Volcando datos para la tabla tienda_electronica.detalle: ~24 rows (aproximadamente)
/*!40000 ALTER TABLE `detalle` DISABLE KEYS */;
INSERT IGNORE INTO `detalle` (`ID_Detalle`, `Cod_Barras`, `Cantidad`, `Sub_Total`) VALUES
	(1, '8766135855MX', 3, 749.97),
	(1, '21654651651MX', 3, 14399.97),
	(2, '8766135855MX', 2, 499.98),
	(3, '3468432415MX', 2, 4799.98),
	(3, '3548763548MX', 1, 3499.99),
	(4, '35749864135MX', 5, 24999.95),
	(5, '3548763548MX', 3, 10499.97),
	(6, '3468432415MX', 2, 4799.98),
	(7, '7654216875MX', 2, 9999.98),
	(8, '7654216875MX', 3, 14999.97),
	(8, '8766135855MX', 1, 249.99),
	(9, '7654216875MX', 3, 14399.97),
	(9, '8766135855MX', 4, 959.96),
	(10, '7654216875MX', 1, 4799.99),
	(10, '8766135855MX', 2, 479.98),
	(11, '8766135855MX', 2, 479.98),
	(11, '7654216875MX', 6, 28799.94),
	(12, '7500093796031', 2, 8999.98),
	(13, '7500093796031', 2, 8999.98),
	(14, '7501001164003', 5, 2500),
	(15, '7501001164003', 2, 1000),
	(16, '7500093796031', 3, 13499.97),
	(17, '7501001164003', 3, 1500),
	(18, '123556465MX', 3, 4499.97),
	(19, '7501001164003', 2, 1000),
	(20, '8766135855MX', 1, 239.99),
	(21, '7500093796031', 1, 4499.99);
/*!40000 ALTER TABLE `detalle` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.detalle_factura
CREATE TABLE IF NOT EXISTS `detalle_factura` (
  `ID_detalle` int NOT NULL,
  `Folio` int NOT NULL,
  KEY `folio-factura` (`Folio`),
  KEY `ID_Detalle` (`ID_detalle`),
  CONSTRAINT `folio-factura` FOREIGN KEY (`Folio`) REFERENCES `factura` (`Folio`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `id-detalle` FOREIGN KEY (`ID_detalle`) REFERENCES `detalle` (`ID_Detalle`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Volcando datos para la tabla tienda_electronica.detalle_factura: ~17 rows (aproximadamente)
/*!40000 ALTER TABLE `detalle_factura` DISABLE KEYS */;
INSERT IGNORE INTO `detalle_factura` (`ID_detalle`, `Folio`) VALUES
	(1, 1),
	(2, 2),
	(3, 3),
	(4, 4),
	(5, 5),
	(6, 6),
	(7, 7),
	(8, 8),
	(9, 9),
	(10, 10),
	(11, 11),
	(12, 12),
	(13, 13),
	(14, 14),
	(15, 15),
	(16, 16),
	(17, 17),
	(18, 18),
	(19, 19),
	(20, 20),
	(21, 21);
/*!40000 ALTER TABLE `detalle_factura` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.empleados
CREATE TABLE IF NOT EXISTS `empleados` (
  `codigo` int NOT NULL AUTO_INCREMENT,
  `nombre` varchar(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `edad` tinyint NOT NULL DEFAULT '20',
  `telefono` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `RFC` varchar(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `num_suc` int DEFAULT '1',
  `contrasena` varchar(70) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `tipo` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT 'E',
  PRIMARY KEY (`codigo`),
  UNIQUE KEY `nombre` (`nombre`),
  UNIQUE KEY `telefono` (`telefono`),
  UNIQUE KEY `RFC` (`RFC`),
  KEY `num_suc` (`num_suc`),
  CONSTRAINT `empleado-suc` FOREIGN KEY (`num_suc`) REFERENCES `sucursales` (`id_sucursal`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci COMMENT='Aqui es donde se llevara acabo el registro de empleados';

-- Volcando datos para la tabla tienda_electronica.empleados: ~8 rows (aproximadamente)
/*!40000 ALTER TABLE `empleados` DISABLE KEYS */;
INSERT IGNORE INTO `empleados` (`codigo`, `nombre`, `edad`, `telefono`, `RFC`, `num_suc`, `contrasena`, `tipo`) VALUES
	(1, 'Brandon', 20, '3321306527', '315987641', 4, '8df399db12a082215e55d87b1617af3c', 'E'),
	(2, 'Carlos', 20, '3313143493', '32415645', 2, '87436850548d1f9a444f1d9732fd6949', 'S'),
	(3, 'Santos', 22, '3325060161', '16574894', 3, 'e2f7feb50902e4dbdf507d98de209662', 'S'),
	(4, 'Jhonny', 20, '3334889386', '21468795', 1, '25a2129a1a39e8223b89655fbf683d7b', 'S'),
	(5, 'Alexander', 20, '3317995678', '35749874', 5, '99067f2dae077d7e65392cc47b547195', 'E'),
	(6, 'Pablo', 20, '3316383829', '7894654', 1, 'ae27a7efbc430323b0141eecfd91c2d9', 'E'),
	(7, 'Luna', 20, '3311926478', '98765468', 2, 'bd364ae29a9d3aefb93989c67a0c9ca2', 'E'),
	(8, 'Jose', 20, '4498679087', '65493488', 2, '5b851850d75e1ffacbaaffeaade9c292', 'E');
/*!40000 ALTER TABLE `empleados` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.empleado_detalle
CREATE TABLE IF NOT EXISTS `empleado_detalle` (
  `Codigo_Empleado` int NOT NULL,
  `Codigo_Venta` int NOT NULL,
  KEY `codigo-empleado` (`Codigo_Empleado`),
  KEY `venta-detalle` (`Codigo_Venta`),
  CONSTRAINT `codigo-empleado` FOREIGN KEY (`Codigo_Empleado`) REFERENCES `empleados` (`codigo`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `venta-detalle` FOREIGN KEY (`Codigo_Venta`) REFERENCES `detalle` (`ID_Detalle`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Volcando datos para la tabla tienda_electronica.empleado_detalle: ~17 rows (aproximadamente)
/*!40000 ALTER TABLE `empleado_detalle` DISABLE KEYS */;
INSERT IGNORE INTO `empleado_detalle` (`Codigo_Empleado`, `Codigo_Venta`) VALUES
	(4, 1),
	(4, 2),
	(2, 3),
	(2, 4),
	(2, 5),
	(2, 6),
	(4, 7),
	(4, 8),
	(4, 9),
	(4, 10),
	(4, 11),
	(4, 12),
	(4, 13),
	(4, 14),
	(4, 15),
	(4, 16),
	(4, 17),
	(4, 18),
	(4, 19),
	(4, 20),
	(4, 21);
/*!40000 ALTER TABLE `empleado_detalle` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.factura
CREATE TABLE IF NOT EXISTS `factura` (
  `Folio` int NOT NULL AUTO_INCREMENT,
  `ID_Cliente` int NOT NULL,
  `Total` double NOT NULL,
  `ID_Empleado` int NOT NULL,
  `ID_Sucursal` int NOT NULL,
  `fecha` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`Folio`),
  KEY `id-cliente` (`ID_Cliente`),
  KEY `id-empleado` (`ID_Empleado`),
  KEY `id-sucursal` (`ID_Sucursal`),
  CONSTRAINT `id-cliente` FOREIGN KEY (`ID_Cliente`) REFERENCES `cliente` (`Codigo`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `id-empleado` FOREIGN KEY (`ID_Empleado`) REFERENCES `empleados` (`codigo`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `id-sucursal` FOREIGN KEY (`ID_Sucursal`) REFERENCES `sucursales` (`id_sucursal`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Volcando datos para la tabla tienda_electronica.factura: ~17 rows (aproximadamente)
/*!40000 ALTER TABLE `factura` DISABLE KEYS */;
INSERT IGNORE INTO `factura` (`Folio`, `ID_Cliente`, `Total`, `ID_Empleado`, `ID_Sucursal`, `fecha`) VALUES
	(1, 1, 17573.9304, 4, 1, '2020-11-10 21:16:32'),
	(2, 2, 579.9768, 4, 3, '2020-11-10 23:55:47'),
	(3, 1, 9627.9652, 2, 2, '2020-11-11 00:19:01'),
	(4, 3, 28999.942, 2, 2, '2020-11-11 00:21:00'),
	(5, 8, 12179.9652, 2, 2, '2020-11-11 00:26:46'),
	(6, 4, 5567.9768, 2, 2, '2020-11-11 00:37:27'),
	(7, 2, 11599.9768, 4, 1, '2020-11-11 00:39:24'),
	(8, 5, 17689.9536, 4, 1, '2020-11-11 00:40:42'),
	(9, 6, 17817.5188, 4, 1, '2020-11-13 01:45:38'),
	(10, 7, 6124.7652, 4, 1, '2020-11-13 12:29:38'),
	(11, 4, 33964.7072, 4, 1, '2020-11-21 23:49:56'),
	(12, 3, 10439.9768, 4, 1, '2020-11-27 18:48:51'),
	(13, 6, 10439.9768, 4, 1, '2020-11-27 18:50:11'),
	(14, 5, 2900, 4, 1, '2020-11-27 18:58:07'),
	(15, 3, 1160, 4, 1, '2020-11-27 19:00:58'),
	(16, 2, 15659.9652, 4, 1, '2020-11-27 19:02:27'),
	(17, 1, 1740, 4, 1, '2020-11-27 19:52:25'),
	(18, 2, 5219.9652, 4, 1, '2020-11-27 20:14:41'),
	(19, 4, 1160, 4, 1, '2020-11-28 13:12:08'),
	(20, 4, 278.3884, 4, 1, '2020-11-29 00:26:50'),
	(21, 8, 5219.9884, 4, 1, '2020-11-29 00:33:49');
/*!40000 ALTER TABLE `factura` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.inventario
CREATE TABLE IF NOT EXISTS `inventario` (
  `Codigo` int NOT NULL,
  `Num_Sucursal` int NOT NULL,
  `Producto` varchar(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT 'Teclado',
  `Entrada_Cantidad` int NOT NULL,
  `Salida_Cantidad` int NOT NULL,
  `Movimiento` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `Precio` double NOT NULL,
  `Precio_cliente` double NOT NULL,
  `stock` int NOT NULL,
  `Fecha_Movimiento` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`Codigo`),
  KEY `inv-numsuc` (`Num_Sucursal`),
  CONSTRAINT `inv-numsuc` FOREIGN KEY (`Num_Sucursal`) REFERENCES `sucursales` (`id_sucursal`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Volcando datos para la tabla tienda_electronica.inventario: ~19 rows (aproximadamente)
/*!40000 ALTER TABLE `inventario` DISABLE KEYS */;
INSERT IGNORE INTO `inventario` (`Codigo`, `Num_Sucursal`, `Producto`, `Entrada_Cantidad`, `Salida_Cantidad`, `Movimiento`, `Precio`, `Precio_cliente`, `stock`, `Fecha_Movimiento`) VALUES
	(1, 1, 'MI BAND 4', 0, 4, 'SALIDA', 199.99, 239.99, 20, '2020-11-12 01:21:23'),
	(2, 1, 'GFORCE 1080TI', 10, 5, 'ENTRADA/SALIDA', 4499.99, 4799.99, 17, '2020-11-12 18:55:08'),
	(3, 2, 'RADEON VEGA 8', 0, 3, 'SALIDA', 1999.99, 2399.99, 10, '2020-10-24 12:12:12'),
	(4, 7, 'REDMI 8', 14, 0, 'ENTRADA', 4799.99, 8399.99, 34, '2020-03-21 05:23:12'),
	(5, 6, 'GFORCE RTX 3090 TI', 0, 7, 'SALIDA', 9499.99, 10399.99, 23, '2020-05-21 02:43:15'),
	(6, 5, 'SDD 1TB GAMIX S11 PRO', 0, 4, 'SALIDA', 2399.99, 3399.99, 43, '2020-07-22 04:23:14'),
	(7, 4, 'RYZEN 3 2300U', 3, 0, 'ENTRADA', 3499.99, 4499.99, 21, '2020-08-27 08:45:13'),
	(8, 3, 'APPLE WHATCH 3 PRO', 0, 9, 'SALIDA', 4999.99, 7399.99, 25, '2020-11-29 11:42:12'),
	(9, 2, 'RADEON VEGA 8', 0, 10, 'SALIDA', 2299.99, 5999.99, 22, '2020-12-04 12:53:15'),
	(10, 1, 'GFORCE 1080TI', 23, 0, 'ENTRADA', 4999.99, 7999.99, 21, '2020-03-24 02:23:14'),
	(11, 8, 'MI BAND 4', 0, 3, 'SALIDA', 239.99, 799.99, 43, '2020-06-14 01:13:18'),
	(12, 8, 'REDMI 8', 2, 0, 'ENTRADA', 4799.99, 8399.99, 42, '2020-05-29 08:22:43'),
	(14, 4, 'GFORCE RTX 3090 TI', 3, 0, 'ENTRADA', 9499.99, 10399.99, 12, '2020-02-20 02:22:43'),
	(15, 5, 'SDD 1TB GAMIX S11 PRO', 7, 0, 'ENTRADA', 2399.99, 3399.99, 14, '2020-07-30 01:32:32'),
	(16, 1, 'RYZEN 3 2300U', 12, 0, 'ENTRADA', 3499.99, 4499.99, 15, '2020-06-22 04:42:40'),
	(17, 2, 'APPLE WHATCH 3 PRO', 0, 5, 'SALIDA', 4999.99, 7399.99, 23, '2020-08-21 06:52:30'),
	(18, 2, 'RADEON VEGA 8', 22, 0, 'ENTRADA', 2299.99, 5999.99, 24, '2020-09-19 11:02:19'),
	(19, 6, 'GFORCE 1080TI', 0, 7, 'SALIDA', 4999.99, 7999.99, 19, '2020-10-18 10:32:18'),
	(20, 3, 'MI BAND 4', 0, 1, 'SALIDA', 239.99, 799.99, 11, '2020-11-15 09:43:11'),
	(21, 1, 'MOUSE', 10, 0, 'ENTRADA', 400, 450, 18, '2020-11-28 13:14:19');
/*!40000 ALTER TABLE `inventario` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.marcas
CREATE TABLE IF NOT EXISTS `marcas` (
  `mar_id` int NOT NULL DEFAULT '0',
  `mar_nombre` varchar(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`mar_id`),
  UNIQUE KEY `mar_nombre` (`mar_nombre`),
  KEY `mar_id` (`mar_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Volcando datos para la tabla tienda_electronica.marcas: ~8 rows (aproximadamente)
/*!40000 ALTER TABLE `marcas` DISABLE KEYS */;
INSERT IGNORE INTO `marcas` (`mar_id`, `mar_nombre`) VALUES
	(5, 'AMD'),
	(1, 'APPLE'),
	(6, 'ASUS'),
	(8, 'HP'),
	(3, 'HUAWEI'),
	(4, 'NVIDIA'),
	(7, 'TOSHIBA'),
	(2, 'XIAOMI');
/*!40000 ALTER TABLE `marcas` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.productos
CREATE TABLE IF NOT EXISTS `productos` (
  `codigo_bar` varchar(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT '1111111111',
  `nombre` varchar(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT 'Teclado',
  `stock` int NOT NULL DEFAULT '0',
  `precio` double(22,2) NOT NULL DEFAULT '0.00',
  `id_marca` int NOT NULL DEFAULT '0',
  `id_proveedor` int NOT NULL DEFAULT '0',
  `id_sucursal` int NOT NULL DEFAULT '0',
  KEY `id_proveedor` (`id_proveedor`),
  KEY `id_sucursal` (`id_sucursal`),
  KEY `marca` (`id_marca`) USING BTREE,
  KEY `codigo_bar` (`codigo_bar`),
  CONSTRAINT `pro-marcas` FOREIGN KEY (`id_marca`) REFERENCES `marcas` (`mar_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `pro-proveedor` FOREIGN KEY (`id_proveedor`) REFERENCES `proveedores` (`id_proveedor`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `pro-sucursal` FOREIGN KEY (`id_sucursal`) REFERENCES `sucursales` (`id_sucursal`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci COMMENT='Aqui se almacenaran los productos de las sucursales\r\n';

-- Volcando datos para la tabla tienda_electronica.productos: ~12 rows (aproximadamente)
/*!40000 ALTER TABLE `productos` DISABLE KEYS */;
INSERT IGNORE INTO `productos` (`codigo_bar`, `nombre`, `stock`, `precio`, `id_marca`, `id_proveedor`, `id_sucursal`) VALUES
	('123556465MX', 'RAM 8GB SAMSUMG 2666HZ', 7, 1499.99, 3, 2, 1),
	('21654651651MX', 'REDMI 8', 20, 4799.99, 2, 2, 7),
	('21654654123MX', 'GFORCE RTX 3090TI', 10, 9499.99, 4, 5, 3),
	('3468432415MX', 'SSD 1TB GAMIX S11 PRO', 13, 2399.99, 6, 4, 2),
	('3548763548MX', 'RYZEN 3 2300U', 6, 3499.99, 5, 7, 2),
	('35749864135MX', 'APPLE WATCH 3 PRO', 15, 4999.99, 1, 2, 2),
	('5498323574MX', 'RADEON VEGA 8', 5, 2299.99, 5, 3, 2),
	('7500093796031', 'iPAD MINI 3 WIFI', 12, 4499.99, 1, 2, 1),
	('7654216875M', 'GFORCE 1080TI', 7, 4799.99, 4, 1, 1),
	('8766135855MX', 'MI BAND 4', 11, 239.99, 2, 1, 1),
	('7501001164003', 'MOUSE', 18, 450.00, 6, 2, 1),
	('7501361111501', 'TECLADO RGB', 16, 1499.99, 7, 4, 1);
/*!40000 ALTER TABLE `productos` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.proveedores
CREATE TABLE IF NOT EXISTS `proveedores` (
  `id_proveedor` int NOT NULL DEFAULT '0',
  `nombre_proveedor` varchar(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT 'Pedro',
  `estado_proveedor` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT 'A',
  PRIMARY KEY (`id_proveedor`),
  UNIQUE KEY `nombre_proveedor` (`nombre_proveedor`),
  KEY `id_proveedor` (`id_proveedor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci COMMENT='Tabla donde se muestran los proveedores\r\n';

-- Volcando datos para la tabla tienda_electronica.proveedores: ~8 rows (aproximadamente)
/*!40000 ALTER TABLE `proveedores` DISABLE KEYS */;
INSERT IGNORE INTO `proveedores` (`id_proveedor`, `nombre_proveedor`, `estado_proveedor`) VALUES
	(1, 'INGRAM', 'A'),
	(2, 'MICRO-KERNEL', 'A'),
	(3, 'PCH', 'A'),
	(4, 'G2', 'A'),
	(5, 'NVIDIA', 'A'),
	(6, 'CANON', 'A'),
	(7, 'IBM', 'A'),
	(8, 'EPSON', 'A');
/*!40000 ALTER TABLE `proveedores` ENABLE KEYS */;

-- Volcando estructura para tabla tienda_electronica.sucursales
CREATE TABLE IF NOT EXISTS `sucursales` (
  `id_sucursal` int NOT NULL DEFAULT '0',
  `Direccion` varchar(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`id_sucursal`),
  UNIQUE KEY `Direccion` (`Direccion`),
  KEY `id_sucursal` (`id_sucursal`)
) ENGINE=InnoDB CHARSET=utf8 COLLATE=utf8_unicode_ci COMMENT='Aqui se muestran las sucursales disponibles.';

-- Volcando datos para la tabla tienda_electronica.sucursales: ~8 rows (aproximadamente)
/*!40000 ALTER TABLE `sucursales` DISABLE KEYS */;
INSERT IGNORE INTO `sucursales` (`id_sucursal`, `Direccion`) VALUES
	(7, 'Av. Federalismo'),
	(6, 'Av. Independencia'),
	(4, 'Av. Juarez'),
	(5, 'Av. La Paz'),
	(3, 'Av. Lopez Mateos'),
	(8, 'Av. Revolucion'),
	(2, 'Fisherman'),
	(1, 'Siempreviva');
/*!40000 ALTER TABLE `sucursales` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
