.. image::  https://travis-ci.org/CiscoDevNet/ydk-py.svg?branch=master
    :target: https://travis-ci.org/CiscoDevNet/ydk-py

.. image:: https://img.shields.io/docker/automated/jrottenberg/ffmpeg.svg
    :alt: Docker Automated build
    :target: https://hub.docker.com/r/ydkdev/ydk-py/

=============================
YANG Development Kit (Python)
=============================

.. contents:: Table of Contents

Overview
--------

The YANG Development Kit (YDK) is a Software Development Kit that provides API's that are modeled in YANG. 
The main goal of YDK is to reduce the learning curve of YANG data models by expressing the model semantics in an API and abstracting protocol/encoding details.  
YDK is composed of a core package that defines services and providers, plus one or more module bundles that are based on YANG models.

Backward Compatibility
----------------------

Due to changes in Entity class this release of YDK in general is not compatible with model bundles generated with previous YDK releases. 
However model bundles for Python generated with YDK-0.7.3 are still compatible with this release.
Please see `the release notes <https://github.com/CiscoDevNet/ydk-py/releases/tag/0.8.1>`_ for details. 

Docker
------

A `docker image <https://docs.docker.com/engine/reference/run/>`_ is automatically built with the latest ydk-py installed. This be used to run ydk-py without installing anything natively on your machine.

To use the docker image, `install docker <https://docs.docker.com/install/>`_ on your system and run the below command. See the `docker documentation <https://docs.docker.com/engine/reference/run/>`_ for more details::

  docker run -it ydkdev/ydk-py


System Requirements
-------------------

Linux
~~~~~

**Ubuntu (Debian-based)**

The following packages must be present in your system before installing YDK-Py::

   # Install Third-party software
   $ sudo apt-get install gdebi-core python3-dev python-dev libtool-bin  
   $ sudo apt-get install libcurl4-openssl-dev libpcre3-dev libssh-dev libxml2-dev libxslt1-dev cmake
   
Download and install YDK core library `libydk`. You can install the library using prebuilt debian packages for Xenial and Bionic LTS distributions. 
For other Ubuntu distributions it is recommended to build core library from source.

For Xenial (Ubuntu 16.04.4)::

   # Upgrade compiler to gcc 5.*
   $ sudo apt-get install gcc-5 g++-5 -y > /dev/null
   $ sudo ln -sf /usr/bin/gcc-5 /usr/bin/cc
   $ sudo ln -sf /usr/bin/g++-5 /usr/bin/c++

   $ wget https://devhub.cisco.com/artifactory/debian-ydk/0.8.1/xenial/libydk_0.8.1-1_amd64.deb
   $ sudo gdebi libydk_0.8.1-1_amd64.deb

For Bionic (Ubuntu 18.04.1)::

   $ wget https://devhub.cisco.com/artifactory/debian-ydk/0.8.1/bionic/libydk_0.8.1-1_amd64.deb
   $ sudo gdebi libydk_0.8.1-1_amd64.deb

**Centos (Fedora-based)**

The following packages must be present in your system before installing YDK-Py. Currently, only Centos7/RHEL7 are known to work::

   # Install Third-party software
   $ sudo yum install epel-release
   $ sudo yum install libssh-devel gcc-c++ python-devel python3-devel
   
   # Upgrade compiler to gcc 5.*
   $ sudo yum install centos-release-scl -y > /dev/null
   $ sudo yum install devtoolset-4-gcc* -y > /dev/null
   $ sudo ln -sf /opt/rh/devtoolset-4/root/usr/bin/gcc /usr/bin/cc
   $ sudo ln -sf /opt/rh/devtoolset-4/root/usr/bin/g++ /usr/bin/c++

   # Install YDK core library
   $ sudo yum install https://devhub.cisco.com/artifactory/rpm-ydk/0.8.1/libydk-0.8.1-1.x86_64.rpm

MacOS
~~~~~

It is required to install Xcode command line tools, `homebrew <http://brew.sh>`_ and the following homebrew packages on your system before installing YDK-Py.

You can download the latest python package from `here <https://www.python.org/downloads/>`_. 
Please do not use the homebrew version of python as it causes issues with installing ydk packages. Please execute ``brew rm python python3`` to remove any homebrew python packages::

   $ xcode-select --install
   $ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
   $ brew install pkg-config libssh xml2 libxml2 curl pcre cmake pybind11

   $ curl -O https://devhub.cisco.com/artifactory/osx-ydk/0.8.1/libydk-0.8.1-Darwin.pkg
   $ sudo installer -pkg libydk-0.8.1-Darwin.pkg -target /

Libssh Installation
-------------------

The libssh-0.8.0 `does not support <http://api.libssh.org/master/libssh_tutor_threads.html>`_ separate threading library, 
which is required for YDK. If after installation of libssh package the `libssh_threads.a` is missing, please downgrade the installation to libssh-0.7.6, 
or upgrade to libssh-0.8.1 or higher.


gNMI Requirements
-----------------

In order to enable YDK support for gNMI protocol, which is optional, the following third party software must be installed prior to gNMI YDK component installation.

Install protobuf and protoc
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: sh

    $ wget https://github.com/google/protobuf/releases/download/v3.5.0/protobuf-cpp-3.5.0.zip
    $ unzip protobuf-cpp-3.5.0.zip
    $ cd protobuf-3.5.0
    $ ./configure
    $ make
    $ sudo make install
    $ sudo ldconfig

Install gRPC
~~~~~~~~~~~~

.. code-block:: sh

    $ git clone -b v1.9.1 https://github.com/grpc/grpc
    $ cd grpc
    $ git submodule update --init
    $ make
    $ sudo make install
    $ sudo ldconfig

Instal YDK gNMI library
~~~~~~~~~~~~~~~~~~~~~~~

**Ubuntu**

For Xenial (Ubuntu 16.04.4)::

   $ wget https://devhub.cisco.com/artifactory/debian-ydk/0.8.1/xenial/libydk_gnmi_0.4.0-1_amd64.deb
   $ sudo gdebi libydk_gnmi_0.4.0-1_amd64.deb

For Bionic (Ubuntu 18.04.1)::

   $ wget https://devhub.cisco.com/artifactory/debian-ydk/0.8.1/bionic/libydk_gnmi_0.4.0-1_amd64.deb
   $ sudo gdebi libydk_gnmi_0.4.0-1_amd64.deb

**CentOS**::

   $ sudo yum install https://devhub.cisco.com/artifactory/rpm-ydk/0.8.1/libydk_gnmi_0.4.0-1.x86_64.rpm

**MacOS**::

   $ curl -O https://devhub.cisco.com/artifactory/osx-ydk/0.8.1/libydk_gnmi-0.4.0-Darwin.pkg
   $ sudo installer -pkg libydk_gnmi-0.4.0-Darwin.pkg -target /

Runtime environment
~~~~~~~~~~~~~~~~~~~

There is an open issue with gRPC on Centos/Fedora, which requires an extra step before running any YDK gNMI application. See this issue on `GRPC GitHub <https://github.com/grpc/grpc/issues/10942#issuecomment-312565041>`_ 
for details. As a workaround, the YDK based application runtime environment must include setting of `LD_LIBRARY_PATH` variable::

    $ PROTO="/Your-Protobuf-and-Grpc-installation-directory"
    $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PROTO/grpc/libs/opt:$PROTO/protobuf-3.5.0/src/.libs:/usr/local/lib64

Python Requirements
-------------------

YDK supports both Python2 and Python3 versions.  At least Python2.7 or Python3.4 must be installed on your system. 

It is also required for Python installation to include corresponding shared library. As example: 

 - python2.7  - /usr/lib/x86_64-linux-gnu/libpython2.7.so
 - python3.5m - /usr/lib/x86_64-linux-gnu/libpython3.5m.so
 
Please follow `System Requirements` to assure presence of shared Python libraries.

How to install
--------------

Quick Install
~~~~~~~~~~~~~

You can install the latest model packages from the Python package index.  Note that, in some systems, you need to install the new package as root.  
You get a fully operational YDK environment by installing the ``cisco-ios-xr`` and/or ``cisco-ios-xe`` bundle(s) (depending on whether you're developing for an IOS XR or IOS XE platform), 
which automatically installs all other YDK-related packages (``ydk``, ``openconfig`` and ``ietf`` packages)::

  $ pip install ydk-models-cisco-ios-xr
  $ pip install ydk-models-cisco-ios-xe

Alternatively, you can perform a partial installation.  If you only want to install the ``openconfig`` bundle and its dependencies (``ydk`` and ``ietf`` packages), execute::

  $ pip install ydk-models-openconfig

If you only want to install the ``ietf`` bundle and its dependencies (``ydk`` package), execute::

  $ pip install ydk-models-ietf

To installation of model bundles on CentOS/RedHat platforms require special handling; please follow the below steps.

**Python2.7**::

    pip install ydk
    pip install --install-option="--install-purelib=/usr/lib64/python2.7/site-packages" --no-deps ydk-models-ietf
    pip install --install-option="--install-purelib=/usr/lib64/python2.7/site-packages" --no-deps ydk-models-openconfig
    pip install --install-option="--install-purelib=/usr/lib64/python2.7/site-packages" --no-deps ydk-models-cisco-ios-xr
    pip install --install-option="--install-purelib=/usr/lib64/python2.7/site-packages" --no-deps ydk-models-cisco-ios-xe

**Python3.4**::

    pip install ydk
    pip install --install-option="--install-purelib=/usr/lib64/python3.4/site-packages" --no-deps ydk-models-ietf
    pip install --install-option="--install-purelib=/usr/lib64/python3.4/site-packages" --no-deps ydk-models-openconfig
    pip install --install-option="--install-purelib=/usr/lib64/python3.4/site-packages" --no-deps ydk-models-cisco-ios-xr
    pip install --install-option="--install-purelib=/usr/lib64/python3.4/site-packages" --no-deps ydk-models-cisco-ios-xe

**Python3.6**::

    pip install ydk
    pip install --install-option="--install-purelib=/usr/lib64/python3.6/site-packages" --no-deps ydk-models-ietf
    pip install --install-option="--install-purelib=/usr/lib64/python3.6/site-packages" --no-deps ydk-models-openconfig
    pip install --install-option="--install-purelib=/usr/lib64/python3.6/site-packages" --no-deps ydk-models-cisco-ios-xr
    pip install --install-option="--install-purelib=/usr/lib64/python3.6/site-packages" --no-deps ydk-models-cisco-ios-xe

Installing from Source
~~~~~~~~~~~~~~~~~~~~~~

If you prefer not to use the YDK packages in the Python package index, you need to install manually the ``ydk`` core package and then the model bundles you plan to use.  
To install the ``ydk`` core package, execute::

  $ cd core
  core$ python setup.py sdist
  core$ pip install dist/ydk*.gz

Once you have installed the ``ydk`` core package, you can install one more model bundles.  Note that some bundles have dependencies on other bundles.  
Those dependencies are already captured in the bundle package.  Make sure you install the desired bundles in the order below.  To install the ``ietf`` bundle, execute::

  core$ cd ../ietf
  ietf$ python setup.py sdist
  ietf$ pip install dist/ydk*.gz

To install the ``openconfig`` bundle, execute::

  ietf$ cd ../openconfig
  openconfig$ python setup.py sdist
  openconfig$ pip install dist/ydk*.gz

To install the ``cisco-ios-xr`` bundle, execute::

  openconfig$ cd ../cisco-ios-xr
  cisco-ios-xr$ python setup.py sdist
  cisco-ios-xr$ pip install dist/ydk*.gz
  cisco-ios-xr$ cd ..

Using a Virtual Environment
~~~~~~~~~~~~~~~~~~~~~~~~~~~
You may want to perform the installation under a Python virtual environment (`virtualenv <https://pypi.python.org/pypi/virtualenv/>`_/`virtualenvwrapper  <https://pypi.python.org/pypi/virtualenvwrapper>`_).  
A virtual environment allows you to install multiple versions of YDK if needed.  In addition, it prevents any potential conflicts between package dependencies in your system.

To install virtual environment support in your system, execute::

  $ pip install virtualenv virtualenvwrapper
  $ source /usr/local/bin/virtualenvwrapper.sh

Create new virtual environment::

  $ mkvirtualenv -p python2.7 ydk-py

At this point, you can perform the quick install or the installation from source described above.  Take into account that must not attempt to install YDK as root under a virtual environment.

Documentation and Support
--------------------------
- Read the `API documentation <http://ydk.cisco.com/py/docs>`_ for details on how to use the API and specific models
- Samples can be found under the `samples directory <https://github.com/CiscoDevNet/ydk-py/tree/master/core/samples>`_
- Hundreds of additional samples can be found in the `YDK-PY samples repository <https://github.com/CiscoDevNet/ydk-py-samples>`_
- Join the `YDK community <https://communities.cisco.com/community/developer/ydk>`_ to connect with other users and with the makers of YDK
- Additional YDK information can be found at `ydk.io <http://ydk.io>`_

Release Notes
--------------

The current YDK release version is 0.8.1. YDK-Py is licensed under the Apache 2.0 License.
