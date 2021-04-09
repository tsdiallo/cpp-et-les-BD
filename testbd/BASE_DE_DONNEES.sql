-- phpMyAdmin SQL Dump
-- version 3.2.0.1
-- http://www.phpmyadmin.net
--
-- Serveur: localhost
-- Généré le : Jeu 19 Février 2015 à 14:23
-- Version du serveur: 5.1.36
-- Version de PHP: 5.3.0

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données: `compte`
--

-- --------------------------------------------------------

--
-- Structure de la table `bloque`
--

CREATE TABLE IF NOT EXISTS `bloque` (
  `numcompte` varchar(10) NOT NULL,
  `proprietaire` varchar(20) NOT NULL,
  `dateOuverture` date NOT NULL,
  `sold` double NOT NULL,
  `Datedebit` date NOT NULL,
  `Datefin` date NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `bloque`
--

INSERT INTO `bloque` (`numcompte`, `proprietaire`, `dateOuverture`, `sold`, `Datedebit`, `Datefin`) VALUES
('A001', 'Ba Ali', '2015-02-11', 200000, '0000-00-00', '0000-00-00'),
('A003', 'Diop Oumar', '2015-02-11', 600000, '0000-00-00', '0000-00-00'),
('c001', 'bf', '2000-02-05', 3000000, '2014-01-01', '2015-03-01');

-- --------------------------------------------------------

--
-- Structure de la table `compteclient`
--

CREATE TABLE IF NOT EXISTS `compteclient` (
  `numcompte` varchar(10) NOT NULL,
  `proprietaire` varchar(20) NOT NULL,
  `dateOuverture` date NOT NULL,
  `sold` double NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `compteclient`
--

INSERT INTO `compteclient` (`numcompte`, `proprietaire`, `dateOuverture`, `sold`) VALUES
('A001', 'Ba Ali', '2015-02-11', 200000),
('A003', 'Camra Oumy', '2015-02-25', 3000000),
('A005', 'Diop Oumar', '2015-02-11', 600000),
('A008', 'Sy Mariam', '2015-02-25', 100000),
('c001', 'bf', '2015-02-05', 3000000),
('c001', 'bf', '2015-02-05', 3000000),
('c001', 'bf', '2015-02-05', 3000000);

-- --------------------------------------------------------

--
-- Structure de la table `courant`
--

CREATE TABLE IF NOT EXISTS `courant` (
  `numcompte` varchar(10) NOT NULL,
  `proprietaire` varchar(20) NOT NULL,
  `dateOuverture` date NOT NULL,
  `sold` double NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `courant`
--

INSERT INTO `courant` (`numcompte`, `proprietaire`, `dateOuverture`, `sold`) VALUES
('A001', 'Ba Ali', '2015-02-11', 200000),
('A004', 'Camra Oumy', '2015-02-25', 3000000),
('A001', 'Diop Oumar', '2015-02-11', 600000),
('A004', 'Sy Mariam', '2015-02-25', 100000),
('c001', 'bf', '2015-02-05', 3000000),
('c001', 'bf', '2015-02-05', 3000000),
('c001', 'bf', '2015-02-05', 3000000),
('D003', 'SY Bokar', '2015-02-05', 3000000);

-- --------------------------------------------------------

--
-- Structure de la table `epargne`
--

CREATE TABLE IF NOT EXISTS `epargne` (
  `numcompte` varchar(10) NOT NULL,
  `proprietaire` varchar(20) NOT NULL,
  `dateOuverture` date NOT NULL,
  `sold` double NOT NULL,
  `soldmin` double NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `epargne`
--

INSERT INTO `epargne` (`numcompte`, `proprietaire`, `dateOuverture`, `sold`, `soldmin`) VALUES
('A001', 'Ba Ali', '2015-02-11', 200000, 0),
('A004', 'Camra Oumy', '2015-02-25', 3000000, 0),
('A001', 'Diop Oumar', '2015-02-11', 600000, 0),
('A004', 'Sy Mariam', '2015-02-25', 100000, 0),
('c001', 'bf', '2015-02-05', 3000000, 80000),
('c001', 'bf', '2015-02-05', 3000000, 80000);
