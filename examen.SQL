-- MariaDB dump 10.18  Distrib 10.5.7-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: examen
-- ------------------------------------------------------
-- Server version	10.5.7-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Factura`
--

DROP TABLE IF EXISTS `Factura`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Factura` (
  `idFactura` int(11) NOT NULL AUTO_INCREMENT,
  `Cliente` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Apellidos` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Productos` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Monto` double DEFAULT NULL,
  `FechaCompra` date DEFAULT NULL,
  `FormatoPago` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`idFactura`)
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Factura`
--

LOCK TABLES `Factura` WRITE;
/*!40000 ALTER TABLE `Factura` DISABLE KEYS */;
INSERT INTO `Factura` VALUES (1,'Esteban Noe','Sarmiento Mtz.','Tamales',25.5,'2020-10-21','Tarjeta'),(4,'Sonia','Alfaro','Pechuga',12.5,'2020-12-12','Efectivo'),(5,'Don Julio','Tovar','Vacas',45.5,'2020-12-12','Credito'),(6,'Algo','Alguien','Comida',12.23,'1997-12-12','Tarjeta'),(7,'Algo','Alguien','Comida',12.23,'2013-11-20','Tarjeta'),(8,'Pedro','Gomez','Compu',6000.99,'2020-12-12','Efectivo'),(9,'Juan','Martinez','Torta de Jamon',10,'2020-12-12','212'),(10,'dsdsad','sadsadsa','dasd',4234,'2020-12-12','3434'),(11,'yutytyutyu','tyutyut','tyutyut',6767,'2020-12-12','567'),(12,'lhjlkjl','ljkljl','jkljk8798',8989,'2020-12-12','9898'),(13,'tuyiyi','yuiyui','uyyiyi',7878.16,'2020-12-12','sdadasd'),(14,'tytrtytry','rtyrtyrty','rtytryrt6546',456456,'2020-12-12','trytrytry'),(15,'wer','ewrewr','werwer',12,'2020-12-12','werewr'),(16,'Señor de la','Tienda','Tamales',12.5,'2020-12-12','Efectivo'),(17,'klñklñkl','ñklñklñ','lkñklñ',90,'2020-12-12','lñklñkl'),(18,'Tguada','sdasd','Pollo',12.505,'2020-12-12','23213'),(19,'sdsadasd','asdasdsa','dasdasd',231231,'2020-12-12','13d1'),(20,'98opp','oipiop','oipiop87',879789,'2020-12-12','lkjklkjl'),(21,'gggdfgdfgg','ergdfggr','gdfgregdgd',3434,'2020-12-12','gdfgdgdfgg'),(22,'hyrthtrrthg','hrhrthtghgfhgfh','gfhrthrthrth',54654654,'2020-12-12','fgngfnfghfg'),(23,'dsfsdfewfsdfewsfdsf','dsfewfwfewffsdfdf','ewfwefdsffswf',123123,'2020-12-12','dfsdfwef'),(24,'Ultimoooo','Ultimoooo','Ultimoooo',2342134324,'2020-12-12','Ultimoooo'),(25,'111111111','1111111','11111111',1111111,'2020-12-12','123123123'),(28,'Tamales','en ','Azucar324',324234,'2020-12-12','dfdsfsdf'),(29,'Atole de Maiz','ewrewr','ewrewr',34234,'2020-12-12','34234'),(30,'rdgtdsgdfgdfgdfg','dfgdfgfdgdfg','dfgdfgdfgfdgdfgdfgdfgdfg',5435435,'2020-12-12','5435435'),(31,'wqewqe','wqewqe','wqewqe',213123,'2020-12-12','213123'),(32,'tghtrhtr','gfhghgfhtr','trytrghg',435435,'2020-12-12','435435'),(33,'geerg','fdgdfgdf','reterte',4534543,'2020-12-12','4534543'),(34,'werewrew','werewrewr','werewr',34324,'2020-12-12','fsdfsdfsdf'),(35,'333333333333','333333333333333','333333333333',3333333333333,'2020-12-12','3333333333333'),(36,'asdadsad','sadsadsa','asdasd',342432,'2020-12-12','czxcxzc'),(37,'444444444444','444444444444444','44444444444',4444444444,'2020-12-12','444444444'),(38,'Autonio','Venavides','Atole',100.5,'2020-12-12','Efectivo'),(39,'Por Fin','Se Pudo','Tamales',12.99,'2020-07-12','Efectivo'),(40,'carlos','sarmiento','Anteojos',355.99,'2019-05-06','Efectivo');
/*!40000 ALTER TABLE `Factura` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`dany`@`localhost`*/ /*!50003 trigger inserta_auditoria_factura after insert on Factura for each row insert into auditoria_factura(clienteNew,ApellidosNew,ProductosNew,MontoNew,FechaCompraNew,FormatoPagoNew,Usuario,Fecha,Accion,idfactura)values(new.Cliente,new.Apellidos,new.Productos,new.Monto,new.FechaCompra,new.FormatoPago,user(),now(),'Dato Insertado',new.idFactura) */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`dany`@`localhost`*/ /*!50003 trigger elimina_auditoria_factura after delete on Factura for each row insert into auditoria_factura(clienteAnt,ApellidosAnt,ProductosAnt,MontoAnt,FechaCompraAnt,FormatoPagoAnt,Usuario,Fecha,Accion,idfactura)values(old.Cliente,old.Apellidos,old.Productos,old.Monto,old.FechaCompra,old.FormatoPago,user(),now(),'Dato Eliminado',old.idFactura) */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `auditoria_factura`
--

DROP TABLE IF EXISTS `auditoria_factura`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auditoria_factura` (
  `idauditoria` int(11) NOT NULL AUTO_INCREMENT,
  `clienteAnt` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `ApellidosAnt` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `ProductosAnt` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `MontoAnt` double DEFAULT NULL,
  `FechaCompraAnt` date DEFAULT NULL,
  `FormatoPagoAnt` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `clienteNew` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `ApellidosNew` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `ProductosNew` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `MontoNew` double DEFAULT NULL,
  `FechaCompraNew` date DEFAULT NULL,
  `FormatoPagoNew` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Usuario` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Fecha` datetime DEFAULT NULL,
  `Accion` varchar(40) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `idfactura` int(11) DEFAULT NULL,
  PRIMARY KEY (`idauditoria`)
) ENGINE=InnoDB AUTO_INCREMENT=43 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auditoria_factura`
--

LOCK TABLES `auditoria_factura` WRITE;
/*!40000 ALTER TABLE `auditoria_factura` DISABLE KEYS */;
INSERT INTO `auditoria_factura` VALUES (1,NULL,NULL,NULL,NULL,NULL,NULL,'Esteban Noe','Sarmiento Mtz.','Tamales',25.5,'2020-10-21','Tarjeta','dany@localhost','2020-10-21 11:15:50','Dato Insertado',1),(2,NULL,NULL,NULL,NULL,NULL,NULL,'Socrates','Valderrama','Libros',100.99,'2020-10-22','Efectivo','dany@localhost','2020-10-21 11:16:41','Dato Insertado',2),(3,NULL,NULL,NULL,NULL,NULL,NULL,'Dionicio','Altamirano','Vino',109.99,'2020-10-22','Efectivo','dany@localhost','2020-10-21 11:17:22','Dato Insertado',3),(4,'Socrates','Valderrama','Libros',100.99,'2020-10-22','Efectivo',NULL,NULL,NULL,NULL,NULL,NULL,'root@localhost','2020-10-21 11:19:34','Dato Eliminado',2),(5,'Dionicio','Altamirano','Vino',109.99,'2020-10-22','Efectivo',NULL,NULL,NULL,NULL,NULL,NULL,'root@localhost','2020-10-21 11:19:37','Dato Eliminado',3),(6,NULL,NULL,NULL,NULL,NULL,NULL,'Sonia','Alfaro','Pechuga',12.5,'2020-12-12','Efectivo','Esteban@localhost','2020-11-15 22:55:09','Dato Insertado',4),(7,NULL,NULL,NULL,NULL,NULL,NULL,'Don Julio','Tovar','Vacas',45.5,'2020-12-12','Credito','Esteban@localhost','2020-11-15 22:58:10','Dato Insertado',5),(8,NULL,NULL,NULL,NULL,NULL,NULL,'Algo','Alguien','Comida',12.23,'1997-12-12','Tarjeta','root@localhost','2020-11-15 23:06:21','Dato Insertado',6),(9,NULL,NULL,NULL,NULL,NULL,NULL,'Algo','Alguien','Comida',12.23,'2013-11-20','Tarjeta','root@localhost','2020-11-15 23:07:19','Dato Insertado',7),(10,NULL,NULL,NULL,NULL,NULL,NULL,'Pedro','Gomez','Compu',6000.99,'2020-12-12','Efectivo','Esteban@localhost','2020-11-15 23:16:09','Dato Insertado',8),(11,NULL,NULL,NULL,NULL,NULL,NULL,'Juan','Martinez','Torta de Jamon',10,'2020-12-12','212','Esteban@localhost','2020-11-15 23:19:33','Dato Insertado',9),(12,NULL,NULL,NULL,NULL,NULL,NULL,'dsdsad','sadsadsa','dasd',4234,'2020-12-12','3434','Esteban@localhost','2020-11-15 23:27:35','Dato Insertado',10),(13,NULL,NULL,NULL,NULL,NULL,NULL,'yutytyutyu','tyutyut','tyutyut',6767,'2020-12-12','567','Esteban@localhost','2020-11-16 10:35:13','Dato Insertado',11),(14,NULL,NULL,NULL,NULL,NULL,NULL,'lhjlkjl','ljkljl','jkljk8798',8989,'2020-12-12','9898','Esteban@localhost','2020-11-16 10:52:00','Dato Insertado',12),(15,NULL,NULL,NULL,NULL,NULL,NULL,'tuyiyi','yuiyui','uyyiyi',7878.16,'2020-12-12','sdadasd','Esteban@localhost','2020-11-16 11:08:51','Dato Insertado',13),(16,NULL,NULL,NULL,NULL,NULL,NULL,'tytrtytry','rtyrtyrty','rtytryrt6546',456456,'2020-12-12','trytrytry','Esteban@localhost','2020-11-16 11:18:41','Dato Insertado',14),(17,NULL,NULL,NULL,NULL,NULL,NULL,'wer','ewrewr','werwer',12,'2020-12-12','werewr','Esteban@localhost','2020-11-16 11:39:35','Dato Insertado',15),(18,NULL,NULL,NULL,NULL,NULL,NULL,'Señor de la','Tienda','Tamales',12.5,'2020-12-12','Efectivo','Esteban@localhost','2020-11-17 13:34:16','Dato Insertado',16),(19,NULL,NULL,NULL,NULL,NULL,NULL,'klñklñkl','ñklñklñ','lkñklñ',90,'2020-12-12','lñklñkl','Esteban@localhost','2020-11-17 13:36:42','Dato Insertado',17),(20,NULL,NULL,NULL,NULL,NULL,NULL,'Tguada','sdasd','Pollo',12.505,'2020-12-12','23213','Esteban@localhost','2020-11-17 13:39:02','Dato Insertado',18),(21,NULL,NULL,NULL,NULL,NULL,NULL,'sdsadasd','asdasdsa','dasdasd',231231,'2020-12-12','13d1','Esteban@localhost','2020-11-17 13:48:18','Dato Insertado',19),(22,NULL,NULL,NULL,NULL,NULL,NULL,'98opp','oipiop','oipiop87',879789,'2020-12-12','lkjklkjl','Esteban@localhost','2020-11-17 13:53:18','Dato Insertado',20),(23,NULL,NULL,NULL,NULL,NULL,NULL,'gggdfgdfgg','ergdfggr','gdfgregdgd',3434,'2020-12-12','gdfgdgdfgg','Esteban@localhost','2020-11-17 13:54:38','Dato Insertado',21),(24,NULL,NULL,NULL,NULL,NULL,NULL,'hyrthtrrthg','hrhrthtghgfhgfh','gfhrthrthrth',54654654,'2020-12-12','fgngfnfghfg','Esteban@localhost','2020-11-17 13:57:48','Dato Insertado',22),(25,NULL,NULL,NULL,NULL,NULL,NULL,'dsfsdfewfsdfewsfdsf','dsfewfwfewffsdfdf','ewfwefdsffswf',123123,'2020-12-12','dfsdfwef','Esteban@localhost','2020-11-17 13:59:36','Dato Insertado',23),(26,NULL,NULL,NULL,NULL,NULL,NULL,'Ultimoooo','Ultimoooo','Ultimoooo',2342134324,'2020-12-12','Ultimoooo','Esteban@localhost','2020-11-17 14:00:13','Dato Insertado',24),(27,NULL,NULL,NULL,NULL,NULL,NULL,'111111111','1111111','11111111',1111111,'2020-12-12','123123123','Esteban@localhost','2020-11-17 14:06:34','Dato Insertado',25),(28,NULL,NULL,NULL,NULL,NULL,NULL,'Aver si','es cierto','ssadasda',23123.23,'2020-12-12','asdasdsad','Esteban@localhost','2020-11-17 14:53:01','Dato Insertado',26),(29,NULL,NULL,NULL,NULL,NULL,NULL,'Nahh','puro','Pito',324234,'2020-12-12','gfgdgfdg','Esteban@localhost','2020-11-17 14:57:13','Dato Insertado',27),(30,NULL,NULL,NULL,NULL,NULL,NULL,'Tamales','en ','Azucar324',324234,'2020-12-12','dfdsfsdf','Esteban@localhost','2020-11-17 14:58:52','Dato Insertado',28),(31,NULL,NULL,NULL,NULL,NULL,NULL,'Atole de Maiz','ewrewr','ewrewr',34234,'2020-12-12','34234','Esteban@localhost','2020-11-17 15:06:42','Dato Insertado',29),(32,NULL,NULL,NULL,NULL,NULL,NULL,'rdgtdsgdfgdfgdfg','dfgdfgfdgdfg','dfgdfgdfgfdgdfgdfgdfgdfg',5435435,'2020-12-12','5435435','Esteban@localhost','2020-11-17 15:08:59','Dato Insertado',30),(33,NULL,NULL,NULL,NULL,NULL,NULL,'wqewqe','wqewqe','wqewqe',213123,'2020-12-12','213123','Esteban@localhost','2020-11-17 15:10:21','Dato Insertado',31),(34,NULL,NULL,NULL,NULL,NULL,NULL,'tghtrhtr','gfhghgfhtr','trytrghg',435435,'2020-12-12','435435','Esteban@localhost','2020-11-17 15:11:39','Dato Insertado',32),(35,NULL,NULL,NULL,NULL,NULL,NULL,'geerg','fdgdfgdf','reterte',4534543,'2020-12-12','4534543','Esteban@localhost','2020-11-17 15:12:10','Dato Insertado',33),(36,NULL,NULL,NULL,NULL,NULL,NULL,'werewrew','werewrewr','werewr',34324,'2020-12-12','fsdfsdfsdf','Esteban@localhost','2020-11-17 15:12:47','Dato Insertado',34),(37,NULL,NULL,NULL,NULL,NULL,NULL,'333333333333','333333333333333','333333333333',3333333333333,'2020-12-12','3333333333333','Esteban@localhost','2020-11-17 15:16:39','Dato Insertado',35),(38,NULL,NULL,NULL,NULL,NULL,NULL,'asdadsad','sadsadsa','asdasd',342432,'2020-12-12','czxcxzc','Esteban@localhost','2020-11-17 15:18:41','Dato Insertado',36),(39,NULL,NULL,NULL,NULL,NULL,NULL,'444444444444','444444444444444','44444444444',4444444444,'2020-12-12','444444444','Esteban@localhost','2020-11-17 15:20:52','Dato Insertado',37),(40,NULL,NULL,NULL,NULL,NULL,NULL,'Autonio','Venavides','Atole',100.5,'2020-12-12','Efectivo','Esteban@localhost','2020-11-17 18:16:41','Dato Insertado',38),(41,NULL,NULL,NULL,NULL,NULL,NULL,'Por Fin','Se Pudo','Tamales',12.99,'2020-07-12','Efectivo','Esteban@localhost','2020-11-17 18:46:09','Dato Insertado',39),(42,NULL,NULL,NULL,NULL,NULL,NULL,'carlos','sarmiento','Anteojos',355.99,'2019-05-06','Efectivo','Esteban@localhost','2020-11-17 18:49:30','Dato Insertado',40);
/*!40000 ALTER TABLE `auditoria_factura` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-11-17 20:12:00
