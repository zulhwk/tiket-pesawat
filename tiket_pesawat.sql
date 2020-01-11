-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 11, 2020 at 09:03 AM
-- Server version: 10.4.8-MariaDB
-- PHP Version: 7.3.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `tiket_pesawat`
--

-- --------------------------------------------------------

--
-- Table structure for table `data_penerbangan`
--

CREATE TABLE `data_penerbangan` (
  `id_penerbangan` varchar(30) NOT NULL,
  `tujuan` varchar(30) DEFAULT NULL,
  `harga` int(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `data_penerbangan`
--

INSERT INTO `data_penerbangan` (`id_penerbangan`, `tujuan`, `harga`) VALUES
('FLG0001', 'Jakarta - Medan', 900000),
('FLG0002', 'Medan - Jakarta', 100000),
('FLG0003', 'Bandung - Jogja', 500000),
('FLG0004', 'Bogor - Jakarta', 800000),
('FLG0005', 'Padang - Jakarta', 400000);

-- --------------------------------------------------------

--
-- Table structure for table `pelanggan`
--

CREATE TABLE `pelanggan` (
  `id_pelanggan` varchar(20) NOT NULL,
  `nama_pelanggan` varchar(20) NOT NULL,
  `alamat` varchar(50) NOT NULL,
  `no_hp` int(20) NOT NULL,
  `pasport` int(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `pelanggan`
--

INSERT INTO `pelanggan` (`id_pelanggan`, `nama_pelanggan`, `alamat`, `no_hp`, `pasport`) VALUES
('PLG0001', 'Yanuardi', 'Jakarta', 98682763, 86728389),
('PLG0002', 'Denia', 'Bogor', 989798, 9799878),
('PLG0003', 'Nurul Fitriani', 'Jakarta', 8682672, 9799233),
('PLG0005', 'Denia Haidar Rinaldi', 'Bogor', 98782683, 89723993),
('PLG0007', 'Jonathan', 'Jakarta', 97878734, 87273883);

-- --------------------------------------------------------

--
-- Table structure for table `transaksi_tiket`
--

CREATE TABLE `transaksi_tiket` (
  `id_transaksi` varchar(20) NOT NULL,
  `id_penerbangan` varchar(20) NOT NULL,
  `id_pelanggan` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transaksi_tiket`
--

INSERT INTO `transaksi_tiket` (`id_transaksi`, `id_penerbangan`, `id_pelanggan`) VALUES
('TRX0001', 'FLG0003', 'PLG0001'),
('TRX0002', 'FLG0004', 'PLG0003'),
('TRX0003', 'FLG0005', 'PLG0005'),
('TRX0006', 'FLG0004', 'PLG0005');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `data_penerbangan`
--
ALTER TABLE `data_penerbangan`
  ADD PRIMARY KEY (`id_penerbangan`);

--
-- Indexes for table `pelanggan`
--
ALTER TABLE `pelanggan`
  ADD PRIMARY KEY (`id_pelanggan`);

--
-- Indexes for table `transaksi_tiket`
--
ALTER TABLE `transaksi_tiket`
  ADD PRIMARY KEY (`id_transaksi`),
  ADD KEY `id_penerbangan` (`id_penerbangan`),
  ADD KEY `id_pelanggan` (`id_pelanggan`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `transaksi_tiket`
--
ALTER TABLE `transaksi_tiket`
  ADD CONSTRAINT `transaksi_tiket_ibfk_1` FOREIGN KEY (`id_penerbangan`) REFERENCES `data_penerbangan` (`id_penerbangan`),
  ADD CONSTRAINT `transaksi_tiket_ibfk_2` FOREIGN KEY (`id_pelanggan`) REFERENCES `pelanggan` (`id_pelanggan`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
