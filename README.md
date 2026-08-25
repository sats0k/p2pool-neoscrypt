# P2Pool NeoScrypt 14.0.0-hybrid (Python 3.14)

A modernized Python 3.14 port of the NeoScrypt P2Pool implementation with PhoenixCoin Quantum hybrid ECDSA/ML-DSA payout support.

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

For PhoenixCoin Quantum hybrid mining, use a daemon build with hybrid address support.
PhoenixCoin Quantum hybrid addresses are supported for direct P2Pool mining. No special `-minehybrid=1` daemon option is required by P2Pool.

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

## Hybrid Mining

PhoenixCoin Quantum supports hybrid ECDSA/ML-DSA payout addresses. This P2Pool version supports mining directly to a hybrid address in addition to traditional PhoenixCoin addresses.

Use the hybrid address as the miner username, for example:

```text
<hybrid-address>
```

The P2Pool share format used by this version includes the payout type so that legacy and hybrid payout scripts can be distinguished correctly.

### P2Pool 14.0.0-hybrid

Hybrid payout support changes the P2Pool share serialization. This release uses the **v14 share format** and the **v14 P2Pool peer protocol**. It is **not compatible with P2Pool v13 peers**.

All P2Pool peers participating in the same sharechain must run **14.0.0-hybrid** (or another implementation using the same v14 share format and peer protocol). P2Pool v13 peers are rejected during the peer handshake, preventing them from joining the v14 sharechain.

Legacy PhoenixCoin payout addresses remain supported; hybrid support does not require all miners to use hybrid addresses.

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
* PhoenixCoin Quantum hybrid ECDSA/ML-DSA payout support
* Direct mining to hybrid payout addresses
* P2Pool 14.0.0-hybrid share format with explicit payout type
* P2Pool v14 peer protocol; P2Pool v13 peers are rejected

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
