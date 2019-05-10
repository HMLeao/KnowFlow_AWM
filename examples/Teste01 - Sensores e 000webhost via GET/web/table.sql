CREATE TABLE IF NOT EXISTS `TANQUE_001`(
	`ID` int(11) NOT NULL AUTO_INCREMENT,
	`TIMESTAMP` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	`DO` double NOT NULL,
	`EC` double NOT NULL,
	`ORP` double NOT NULL,
	`PH` double NOT NULL,
	`TEMPERATURA` double NOT NULL,
	PRIMARY KEY (`ID`)
) DEFAULT CHARSET = utf8;