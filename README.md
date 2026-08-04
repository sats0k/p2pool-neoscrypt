# P2Pool NeoScrypt (Python 3.14)

A modernized Python 3.14 port of the NeoScrypt P2Pool implementation with support for PhoenixCoin Quantum and other NeoScrypt-based cryptocurrencies.

## Requirements

### Generic

* Python **3.14** or newer
* Twisted **26.x** or newer
* zope.interface

### Linux

Install the required Python packages:

```bash
python3 -m pip install twisted zope.interface
```

Or use your distribution packages if available.

### Windows

* Install Python 3.14 or newer
* Install the required Python packages:

```bash
python -m pip install twisted zope.interface
```

Additional packages may be required depending on your mining environment.

---

# Running P2Pool

To use P2Pool, you must run your own local PhoenixCoin daemon.

For a standard configuration:

```bash
python3 run_p2pool.py --net phoenixcoin
```

Then configure your miner to connect to:

```
Host: 127.0.0.1
Port: 10554
```

Any username and password may be used.

If your node should accept incoming P2Pool peers, forward TCP port **10555** to the machine running P2Pool.

To see all available options:

```bash
python3 run_p2pool.py --help
```

---

# NeoScrypt Python Module

P2Pool requires the bundled NeoScrypt Python extension.

Build and install it before running P2Pool.

## Linux

```bash
cd neoscrypt
python3 setup.py build
python3 setup.py install
```

or

```bash
python3 -m pip install .
```

## Windows

Build the extension using a supported Visual Studio toolchain or MinGW compatible with your Python installation.

---

# PhoenixCoin

Run P2Pool with:

```bash
python3 run_p2pool.py --net phoenixcoin
```

Default ports:

| Service |  Port |
| ------- | ----: |
| Stratum | 10554 |
| P2P     | 10555 |

Configure your miner to connect to:

```
127.0.0.1:10554
```

Forward TCP port **10555** if your node should participate in the public P2Pool network.

---

# Project Status

This repository has been successfully migrated from **Python 2.7** to **Python 3.14**.

The following functionality has been restored:

* Python 3.14 compatibility
* Twisted 26 compatibility
* NeoScrypt support
* P2P networking
* Sharechain synchronization
* Stratum mining server
* JSON-RPC communication
* Web interface and statistics
* Block submission to the PhoenixCoin daemon

The project is currently in the stabilization and long-term testing phase.

---

# Official P2Pool Wiki

https://en.bitcoin.it/wiki/P2Pool

---

# Alternate Web Frontend

https://github.com/hardcpp/P2PoolExtendedFrontEnd

---

# License

See the [LICENCE](LICENCE) file.
