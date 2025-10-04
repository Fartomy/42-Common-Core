# :globe_with_meridians: Net Practice

##  🧭 Road Map

1. [IP Adress: Network Layer](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#desert_island-ip-adress-network-layer)
   - [IPv4 - IPv6](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#candy-ipv4---ipv6)
   - [Public Adress - Private Adress](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#ice_cube-public-adress---private-adress)
2. [TCP](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#plate_with_cutlery-tcp)
3. [TCP/IP Adressing](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#mag_right-tcpip-adressing)
4. [OSI Model](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#roller_coaster-osi-model)
   - [MAC Adress (Physical Adress)](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#statue_of_liberty-mac-adress-physical-adress)
5. [Subnet Mask](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#-subnet-mask)
   - [Finding Network Adress](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#roller_skate-finding-the-network-address)
   - [Finding the Range of Host Adress](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#fuelpump-finding-the-range-of-host-addresses)
   - [CIDR Notation (/24)](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#oncoming_automobile-cidr-notation-24)
     - [Mini Infos](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#canoe-mini-infos)
6. [Devices](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#fireworks-devices)
   - [Switch](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#ocean-switch)
   - [Router](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#snowflake-router)
    - [Routing Table](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#open_umbrella-routing-table)
7. [Completed Levels](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#zap-completed-levels)
8. [Resources](https://github.com/Fartomy/42-Kickoff/tree/master/net_practice/Completed_Levels#-resources)


---

## :desert_island: IP Adress: Network Layer

</br>
<p align="center">
  <kbd><img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/01a2bbd9-56ba-4797-9e88-14a880835243" height=300 alt="mask"></kbd>
</p>
</br>

IP is part of an internet protocol suite, which also includes the transmission control protocol. Together, these two are known as TCP/IP. The internet protocol suite governs rules for packetizing, addressing, transmitting, routing, and receiving data over networks.

IP addressing is a logical means of assigning addresses to devices on a network. Each device connected to the internet requires a unique IP address.

An IP address has two parts; one part identifies the host such as a computer or other device, and the other part identifies the network it belongs to. TCP/IP uses a subnet mask to separate them.

### :candy: IPv4 - IPv6

IP addresses come in 2 versions--IPv4 and IPv6: 

```
# IPv4
40.252.255.255

# IPv6
ed14:458b:d1f2:fabd:124f:ad12:da51:eb71
```

Internet Protocol version 4 (IPv4) defines an IP address as a 32-bit number. However, because of the growth of the Internet and the depletion of available IPv4 addresses, a new version of IP (IPv6), using 128 bits for the IP address, was standardized in 1998. However, only IPv4 addresses are used in NetPractice. 

### :ice_cube: Public Adress - Private Adress

A public IP address is an IP address that can be accessed directly over the internet and is assigned to your network router by your internet service provider (ISP). A public (or external) IP address helps you connect to the internet from inside your network, to outside your network.

A private IP address is an address your network router assigns to your device. Each device within the same network is assigned a unique private IP address (sometimes called a private network address) — this is how devices on the same internal network talk to each other.

When a network is connected to the internet, it cannot use an IP address from the reserved private IP addresses. The following ranges are reserved for private IP addresses:

```
192.168.0.0 – 192.168.255.255 (65,536 IP addresses)
172.16.0.0 – 172.31.255.255   (1,048,576 IP addresses)
10.0.0.0 – 10.255.255.255     (16,777,216 IP addresses)
```

## :plate_with_cutlery: TCP

TCP stands for Transmission Control Protocol. It is a communications standard that enables application programs and devices to exchange messages over a network. It is used to send packets across the internet.

TCP guarantees the integrity of the data being communicated over a network. Before it transmits data, TCP establishes a connection between a source and its destination, which remains active until communication begins. It then breaks large amounts of data into smaller packets, while ensuring end-to-end delivery without loss of any data.

## :mag_right: TCP/IP Adressing

</br>
<p align="center">
  <kbd><img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/0ff133d9-1e72-4878-818e-40d166b6c1fd" height=300 alt="mask"></kbd>
</p>
</br>

TCP/IP specifies how data is exchanged over the internet by providing end-to-end communications that identify how it should be broken into packets, addressed, transmitted, routed and received at the destination. TCP/IP requires little central management and is designed to make networks reliable with the ability to recover automatically from the failure of any device on the network.

The two main protocols in the IP suite serve specific functions. TCP defines how applications can create channels of communication across a network. It also manages how a message is assembled into smaller packets before they are then transmitted over the internet and reassembled in the right order at the destination address.

## :roller_coaster: OSI Model

</br>
<p align="center">
  <kbd><img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/53c27b95-0d97-44ed-81b6-0adf3cb91dc0" height=300 alt="mask"></kbd>
</p>
</br>

The OSI (Open Systems Interface) model provides an important theoretical framework for understanding networking and network protocols. This model divides networking into seven layers (layers), with each layer representing a specific function or service. Each layer interacts with the layers below and above it in a specific way.

Today, the OSI model is still important in network engineering, network management, and designing and understanding network protocols. Especially with the increasing complexity of network protocols and network technologies, the OSI model is used to understand and troubleshoot communication processes in the network.

However, in practice, network engineers and system administrators often prefer more specific and application-oriented models (for example, the TCP/IP model). The TCP/IP model is more commonly used to describe internet protocols and facilitate the design and management of TCP/IP-based networks.

Nevertheless, the basic principles of the OSI model and the concepts of interlayer communication continue to provide an important theoretical representation that underpins network engineering and communications technologies. Therefore, the OSI model is still valuable for providing a theoretical basis for networking.

### :statue_of_liberty: MAC Adress (Physical Adress)

</br>
<p align="center">
  <kbd><img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/140eae72-45ad-4276-b57f-778958c382e7" height=300 alt="mask"></kbd>
</p>
</br>

MAC Addresses are unique 48-bit hardware numbers of a computer that are embedded into a network card (known as a Network Interface Card) during manufacturing. The MAC Address is also known as the Physical Address of a network device.

The MAC address is used by the Media Access Control (MAC) sublayer of the Data-Link Layer. MAC Address is worldwide unique since millions of network devices exist and we need to uniquely identify each.

To understand what is MAC address is, it is very important that first you understand the format of the MAC Address. So a MAC Address is a 12-digit hexadecimal number (6-bit binary number), which is mostly represented by Colon-Hexadecimal notation.

The First 6 digits (say 00:40:96) of the MAC Address identify the manufacturer, called the OUI (Organizational Unique Identifier). IEEE Registration Authority Committee assigns these MAC prefixes to its registered vendors.

Here are some OUI of well-known manufacturers:

```
CC:46:D6 - Cisco 
3C:5A:B4 - Google, Inc.
3C:D9:2B - Hewlett Packard
00:9A:CD - HUAWEI TECHNOLOGIES CO.,LTD
```
The rightmost six digits represent Network Interface Controller, which is assigned by the manufacturer. 

As discussed above, the MAC address is represented by Colon-Hexadecimal notation. But this is just a conversion, not mandatory. MAC address can be represented using any of the following formats:

```
# Hypen-Hexadecimal notaion
00-0a-83-b1-c0-8e
# Colon-Hexadecimal notaion
00:0a:83:b1:c0:8e
# Period-separated hexadecimal notaion
000.a83.b1c.08e
```

_Note: Colon-Hexadecimal notation is used by Linux OS and Period-separated Hexadecimal notation is used by Cisco Systems._

## 🤿 Subnet Mask

</br>
<p align="center">
  <kbd><img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/e4636d7b-4373-4e13-83c1-e0f3a82a01ab" height=300 alt="mask"></kbd>
</p>
</br>

A subnet mask is a 32 bits (4 bytes) address used to distinguish between a network address and a host address in the IP address. It defines the range of IP addresses that can be used within a network or a subnet.

The purpose is to reduce network traffic, provide security, and provide subnets by segmenting the network.

### :roller_skate: Finding the network address

_Note: In a subnet, we can think of it as 1 bits representing the network and 0 bits representing the hosts (1 bits and 0 bits wars)_

The _Interface A1_ above has the following properties:

```
IP address | 104.198.241.125
Mask       | 255.255.255.128
```

To determine which portion of the IP address is the network address, we need to apply the mask to the IP address. Let's first convert the mask to its binary form:

```
Mask | 11111111.11111111.11111111.10000000
```

The bits of a mask that are 1 represent the network address, while the remaining bits of a mask that are 0 represent the host address. Let's now convert the IP address to its binary form:

```
IP address | 01101000.11000110.11110001.01111101
Mask       | 11111111.11111111.11111111.10000000
```

We can now apply the mask to the IP address through a [bitwise AND](https://en.wikipedia.org/wiki/Bitwise_operation#AND) to find the network address of the IP:

```
Network address | 01101000.11000110.11110001.00000000
```

Which translates to a network address of `104.198.241.0`.
</br>
</br>

### :fuelpump: Finding the range of host addresses

To determine what host addresses we can use on our network, we have to use the bits of our IP address dedicated to the host address. Let's use our previous IP address and mask:

```
IP address | 01101000.11000110.11110001.01111101
Mask       | 11111111.11111111.11111111.10000000
```

The possible range of our host addresses is expressed through the last 7 bits of the mask which are all 0. Therefore, the range of host addresses is:

```
BINARY  | 0000000 - 1111111
DECIMAL | 0 - 127
```

To get the range of possible IP addresses for our network, we add the range of host addresses to the network address. Our range of possible IP addresses becomes `104.198.241.0 - 104.198.241.127`.

<ins>HOWEVER</ins>, the extremities of the range are reserved for specific uses and cannot be given to an interface:

```
104.198.241.0   | Reserved to represent the network address.
104.198.241.127 | Reserved as the broadcast address; used to send packets to all hosts of a network.
```

Therefore, our real IP range becomes `104.198.241.1 - 104.198.241.126`, which could have been found using an [IP calculator](https://www.calculator.net/ip-subnet-calculator.html).
</br>
</br>

### :oncoming_automobile: CIDR Notation (/24)

The mask can also be represented with the Classless Inter-Domain Routing (CIDR). This form represents the mask as a slash `/`, followed by the number of bits that serve as the network address.

Therefore, the mask in the example above of `255.255.255.128`, is equivalent to a mask of `/25` using the CIDR notation, since 25 bits out of 32 bits represent the network address.

#### :canoe: Mini Infos

`/24` (255.255.255.0) represents a subnet mask and is used in CIDR (Classless Inter-Domain Routing) notation. This notation indicates which part of an IP address is the network part and which part is the host part.

For example, the IP address `192.168.1.0/24` is described as:

    The IP address "192.168.1.0" is the starting IP address of the network.
    The "/24" represents the subnet mask and refers to the first 24 bits (8 bits x 3 octets) of the network segment.

In this case, the expression "192.168.1.0/24" indicates the following:

    Network segment: First three octets (192.168.1)
    Host section: Last octet (0)
    Subnet mask: First 24 bits (255.255.255.0)

The network segment represents a specific range of IP addresses and the devices on this network are located within this IP address range. The `/24` indicates that the first 24 bits of the subnet mask represent the network segment and the remaining bits represent the host segment.

In general, `/24` is a notation used in network design and IP address management to quickly identify the subnet mask of a given IP address range. This notation is quite common to describe the size of the network and IP address distribution.

---

##### :ship: Long Calculation

To convert the subnet mask to CIDR (Classless Inter-Domain Routing) notation, you need to determine how many bits are 1. This is done by counting the 1s. Take the example of the subnet mask `255.255.255.252`:

    255 represents a segment of 8 bits. (11111111)
    255 represents another 8-bit segment. (11111111)
    255 represents another 8-bit segment. (11111111)
    252 represents a 2-bit segment. (11111100)

In total, we have a subnet mask with 8 + 8 + 8 + 8 + 6 = 30 bits 1.

In this case, the CIDR notation would be `/30`. This is because the CIDR notation specifies the number of 1's in the subnet mask. So the subnet mask is `255.255.255.252`, 
It is expressed as `/30` in CIDR notation.

---

##### ⛴️ Short Calculation

Since the IPv4 address is 32 bits long and this is divided into 4 octets, each octet can take from 0 to 255 (0 - 255), i.e. a maximum of 256 numbers from 2^8. 
Since the first 3 of these octets (for the example above) are `255`, we get 24 bits from 3 * 8.

(Note: However, if we consider the `/26` example, it may be difficult to calculate from the shorter calculation, in which case it may be useful to use the longer calculation).

---

##### :rocket: Host Calculation - Number of Devices

The host section will be 32 - the length of the CIDR. For example, for `/24` the host partition will be 32 - 24 = 8 bits. From 2^8 we get the number 256. 
It contains 256 IP addresses, but one of them is a "network address (for example, this is how we can reach the network interface of the modem)" and one is a broadcast address 
(broadcast - an address reserved for sending packets to all devices at the same time), the number of available IP addresses that can be assigned to devices is 256 - 2 = 254.

To understand this situation better:

    Network address: 192.168.1.0
    First available IP: 192.168.1.1
    Last available IP: 192.168.1.254
    Broadcast address 192.168.1.255

Therefore, the subnet `192.168.1.0/24` has 256 IP addresses, but the number of available IP addresses is 254 because the network address and broadcast address are unavailable.

---

##### :parachute: Subnet Calculation
As the number of bits decreases, the number of devices and subnets increases and as the number of bits increases, the number of subnets and devices decreases.

For example, when using the subnet mask `255.255.255.252` we get 22 bits, there is a decrease in the 3rd octet, and when we subtract 252 from 256 we get the number 4, so a network is divided into 4 subnets. If each network (for example `192.168.0.X` -> Subnet 1 - `192.168.1.X` -> Subnet 2 - `192.168.2.X` -> Subnet 3 - `192.168.3.X` -> Subnet 4) has 256 IP addresses, we have a total of 1024 IP addresses. Attention, each of the segmented networks does not have a unique broadcast and network address because the network is 1, what is being done here is actually like classifying the network. Therefore, in the same way, the first address, `192.168.0.0`, will be the network address and `192.168.3.255` will be the broadcast address, so in this case the number of assignable and usable IP addresses will be 1022.

For example, the IP addresses `192.168.0.26` and `192.168.1.54` belong to different subnets when using the subnet mask `255.255.255.252`. In this case, these two IP addresses cannot communicate directly with each other.

When the subnet mask is specified with `255.255.255.252`, the subnets occupy 4 IP addresses each.

The IP addresses `192.168.0.26` and `192.168.1.54` belong to different subnets, one in Subnet 1 and the other in Subnet 2, and therefore cannot communicate directly. 

(They can be thought of as different departments, in fact they are on the same network but on different subnets) In order to communicate between the two devices, a router, etc. must be connected between these two subnets. a router or similar device will need to route the communication between these two subnets.


##### :first_quarter_moon_with_face: Example

In a network, let the subnet mask be `255.255.255.224` and the IP address of one device be `94.54.250.222` and the IP address of the other device be `X`. 
What should be the IP address of the device with IP address `X` in order to communicate with this device `94.54.250.222`?

From the CIDR calculation (calculation of how many of them are 1 bit) it turns out that there are 27 1 bits: "/27"

If the maximum length of IPv4 is 32 bits (i.e. if there are 32 1 bits), then the number of bits 0 of the fourth, last octet is 5 out of 32 - 27 and it is now known that 3 bits are 1 bit out of 8 - 5.

if the number of hosts is "32" from 2^5 and one is a network address and one is a broadcast address, then 32 - 2 gives 30 IP addresses usable on this network.

Together with the given subnet mask `255.255.255.224`, each subnet has 32 IP addresses (2^5 = 32). 
Within these IP addresses, the first IP address represents the network address, the next 30 IP addresses represent the available addresses and the last IP address represents the broadcast address.

Since the number of 0 bits in the last octet is 5, the remaining 1 bit is 3 because they add up to 8 bits.

So this network can divide 2^3 into 8 subnets. Since our maximum number of IPs is 256, each subnet has a maximum of 32 IP addresses from 256 / 8.  (this calculation can be verified from the 2^5 calculated above).

Therefore, a network created with subnet mask `255.255.255.224` can have 8 subnet combinations with 32 IP addresses

These subnets are represented as follows:

```
Network Adress	             Usable Host Range		       Broadcast Adress

94.54.250.0		94.54.250.1 - 94.54.250.30		94.54.250.31
94.54.250.32		94.54.250.33 - 94.54.250.62		94.54.250.63
94.54.250.64		94.54.250.65 - 94.54.250.94		94.54.250.95
94.54.250.96		94.54.250.97 - 94.54.250.126		94.54.250.127
94.54.250.128		94.54.250.129 - 94.54.250.158		94.54.250.159
94.54.250.160		94.54.250.161 - 94.54.250.190		94.54.250.191
94.54.250.192		94.54.250.193 - 94.54.250.222		94.54.250.223
94.54.250.224		94.54.250.225 - 94.54.250.254		94.54.250.255
```

Each subnet contains 32 IP addresses.

> [!WARNING]
> The network address of each combination is different.
> For example, a device with an IP address of `94.54.250.165` and a subnet mask of `255.255.255.224` has a network address of `94.54.250.160`.
> 
> Because a network with such a subnet address of `255.255.255.224` is divided into 8 different subnet combinations, the first address of `94.54.250.165`
> will be the network address `94.54.250.160` and the last address will be the broadcast address `94.54.250.191`.
>
> Or the network address can be found by simply calculating the network address.

> [!TIP]
> We can obtain the binary sequence of a number by using the `echo` and `bc` commands together in bash.
> ```
> # Binary of a number
> echo "obase=2; <number>" | bc
> ```
> Of course, it can also help find the network address.
> Or
> If you want to find the direct network address of a device, the following command can be used.
> ```
> # To find network adress
> echo "$((<number> & <number>))"
> ```
> **Examples**
> To `94.54.250.165` and subnet `255.255.255.224`:
> ```
> $ echo "$((165 & 224))"
> $ 160
> ```
> So, network address is `94.54.250.160`
> Or
> CIDR calculation to `255.255.255.224`
> ```
> $ echo "obase=2; 224" | bc
> $ 11100000
> ```
> So, CIDR is `/27`.

Given a subnet mask of `255.255.255.224` (/27 in CIDR notation), there will be 8 different subnet combinations of these IP addresses and each combination will have a range of 32 levels.
In the first three octets `255.255.255` all bits of the mask are set to 1, so these parts are fixed. But in the fourth octet `224` the first 3 bits are set to 1,  the remaining 5 bits are 0.

In this case, 2^3 or 8 different combinations can be obtained using 3 bits. Each combination represents a subnet. 
When all 3 bits are set to 0 for the first subnet, when the first bit is set to 1 for the next subnet, when the second bit for the second subnet is set to 1 and so on.

These 3 bit combinations are as follows:

```
Subnet: 000
Subnet: 001
Subnet: 010
Subnet: 011
Subnet: 100
Subnet: 101
Subnet: 110
Subnet: 111
```

Each combination represents a subnet. Each of these 8 subnets contains 32 range addresses. Therefore, the network created with subnet mask `255.255.255.224`, Includes 8 different subnet combinations.

_**Different solution:**_

If the last octet is 224, find the difference to add up to 256, 256 - 224 equals 32. This means that each subnet has 32 IP addresses.  

To find how many different subnet combinations there are, 256 / 32 gives 8 different subnet combinations. 

For the CIDR calculation, if we have 8 different subnets, we verify that we get the number 8 from 2^3, so if we say that 3 bits are 1 
Since the first 3 octets (the 1s represent the network) are already 255, we get the CIDR of 24 + 3 `/27`.

</br>

---

## :fireworks: Devices

### :ocean: Switch

</br>
<p align="center">
  <kbd><img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/f92d0ec6-0784-4f34-9b0d-1bd1060899d0" height=150 alt="switch"></kbd>
</p>
</br>

A switch connects multiple devices together in a single network. Unlike a router, the switch does not have any interfaces since it only distributes packets to its local network, and cannot talk directly to a network outside of its own.

---

### :snowflake: Router

</br>
<p align="center">
  <kbd><img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/e744d1f8-7a54-45a3-8b55-31aba9cc4a69" height=200 alt="router"></kbd>
</p>
</br>

Just as the switch connects multiple devices on a single network, the router connects multiple networks together. The router has an interface for each network it connects to.

Since the router separates different networks, the range of possible IP addresses on one of its interfaces must not overlap with the range of its other interfaces. An overlap in the IP address range would imply that the interfaces are on the same network.
</br>
</br>

#### :open_umbrella: Routing Table

</br>
<p align="center">
  <kbd><img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/e45173ab-7d80-482f-97f4-d87a85ef1bd5" height=150 alt="routing_table"></kbd>
</p>
</br>

A routing table is a data table stored in a router or a network host that lists the routes to particular network destinations. In NetPractice, the routing table consists of 2 elements:

- **Destination**: The destination specifies a network address on which a host is the end target of the packets. The route of `default` or `0.0.0.0/0`, is the route that takes effect when no other route is available for an IP destination address. The default route will use the next-hop address to send the packets on their way without giving a specific destination. The default route will match any network.

- **Next hop**: The next hop refers to the next closest router a packet can go through. It is the IP address of the next router on the packet's way. Every single router maintains its routing table with a next hop address.


For example, in a network there is a router and 1 device each in different subnets:

```
              MachineB --> IP: 152.249.225.253
             /		   Mask: 255.255.192.0    
            /				               Client B: Machine B
           / 	 					     Routes:
          /					    default => 152.249.225.254
         /
        /
      Interface R2 --> IP: 152.249.225.254
      /                Mask: 255.255.192.0
Router
      \
      Interface R1 --> IP: 90.15.153.126
        \             Mask: 255.255.255.128
         \
          \
           \
            \
             \
              MachineA --> IP: 90.15.153.125
                           Mask: 255.255.255.128

                                                   Client A: Machine A
                                                        Routes:
                                            152.249.0.0/16 => 90.15.153.126
```

1. IP Address Range (Destination): `152.249.0.0/16` refers to an IP address range. This expression includes all IP addresses starting from IP address `152.249.0.0` up to IP address `152.249.255.255`. The notation `/16` indicates that the first two 16 bits (1st and 2nd byte) of this IP range represent the network address. This includes all IP addresses starting with `152.249`.

2. Router IP Address (Next Hop): `90.15.153.126` represents the IP address of the router. This IP address is the IP address assigned to an interface of a router on the network. Hosts communicate using this router IP address and the router provides this communication by routing between different networks.

3. **default**:

In the IP address range, the term `default` usually refers to a default gateway. This means the default route used when routing traffic if the destination IP address that a device wants to communicate with is not on the same subnet.

Typically, the default gateway specified in a computer or device's network settings is used to reach destinations outside the device's network. If the IP address a device wants to communicate with is not on the same subnet, then it is routed through the default gateway.

For example, if a computer's IP address is `192.168.1.10` and its gateway is `192.168.1.1`, then `192.168.1.1` is considered the default gateway. When a computer wants to reach a device on the same subnet, it can communicate directly. However, when it wants to reach a destination that is not on the same subnet, traffic is routed through the default gateway.

The destination `default` is equivalent to `0.0.0.0/0`.

---

## :zap: Completed Levels

<details>
  <summary>Level 1</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/af81441a-97e4-4ff1-b27f-43b41cbf8099" alt="level1">  
  <br>
  <br>

**1.** Since _Client A_ and _Client B_ are on the same network, their IP address must represent the same network in accordance with the subnet mask.
<br>
The subnet mask is _255.255.255.0_, which means that the first 3 bytes of the IP address represent the network, and the 4th byte represents the host. Since we are on the same network, only the host can change.
<br>
The solution will be anything in the range of **104.96.23.0 - 104.96.23.255** excluding the following 3:

- **104.96.23.0:** The first number in the range of hosts (0 in this case) represents the network and cannot be used by a host.
- **104.96.23.255:** The last number in the range of hosts (255 in this case) represents the broadcast address.
- **104.96.23.12:** This address is already used by the host _Client B_.

**2.** The same reasoning as _1._, however the subnet mask is _255.255.0.0_ in this case. The first 2 bytes of the IP address will represent the network; and the last 2 bytes, the host address.
<br>
The solution will be anything in the range of **211.191.0.0 - 211.191.255.255**, excluding:

- **211.191.0.0:** Represents the network address.
- **211.191.255.255:** Represents the broadcast address.
- **211.191.89.75:** Already taken by host _Client C_.

</br>

</details>

---

<details>
  <summary>Level 2</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/b78d4e39-9513-458b-97a6-9559d6d32d0c" alt="level2">
  <br>
  <br>

**1.** Since _Client B_ is on the same private network as _Client A_, they should have the exact same subnet mask.
<br>
The solution can only be **255.255.255.224**.

**2.** To understand the subnet mask of _255.255.255.224_, let's look at it in binary form, along with the IP _192.168.20.222_ of _Client B_:

<center>

```
MASK: 11111111.11111111.11111111.11100000
IP:   11000000.10101000.00010100.11011101
```

</center>
As we can see, the first 27 bits represent the IP address, while only the last 5 bits represent the host address.
<br>
All these 27 bits representing the network must stay the same in the IP addresses of hosts on the same network. To get the answer, we can only change the last 5 bits.
<br>
<br>
The answer is in the range of:

```
BIN:  11000000.10101000.00010100.11000000 - 11000000.10101000.00010100.11011111
or
DEC:  192.168.20.192 - 192.168.20.223
```

Excluding:
<br>

- **11000000.10101000.00010100.11000000:** Represents the network address (notice all 0 in the last 5 bits).
- **11000000.10101000.00010100.11011111:** Represents the broadcast address (notice all 1 in the last 5 bits).
- **11000000.10101000.00010100.11011110:** _Client B_ already has that address.

**3.** Here we are introduced the slash "/" notation for the subnet mask on _Interface D1_. A subnet mask of _/30_ means that the first 30 bits of the IP address represent the network address, and the remaining 2 bits represent the host address:

<center>

```
Mask /30: 11111111.11111111.11111111.11111100
```

</center>

We can see that this binary number corresponds to the decimal _255.255.255.252_, therefore it is identical to the mask found on _Interface C1_.
<br>
<br>
The answers can then be any address, as long as they meet the following conditions:

- The network address (first 30 bits) must be identical for _Client D_ and _Client C_.
- The host bits (last 2 bits) cannot be all 1, nor all 0.
- _Client D_ and _Client C_ do not have identical IP addresses.

</br>

</details>

---

<details>
  <summary>Level 3</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/16cd9c0d-e3bb-48ce-b2f9-b70db33c79f1" alt="level3">
  <br>
  <br>

This exercise introduces the use of the **switch** (_Switch S_ in this example). The switch links multiple hosts of the same network together.
<br>
<br>

**1.** _Client A_, _Client B_, and _Client C_ are all on the same network. Therefore, they must all have the same subnet mask. Since _Client C_ already has the mask _255.255.255.128_, the mask for _Interface B1_ and for _Interface A1_ will also be _255.255.255.128_ (or in slash notation: _/25_).
<br>
<br>
The IP address of _Interface B1_ and _Interface C1_ must be on the same network range as the IP of _Client A_. This range is:

  <center>

```
104.198.241.0 - 104.198.241.128
```

  </center>
  Excluding of course the network address and the broadcast address.

</br>

</details>

---

<details>
  <summary>Level 4</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/a8cc1086-9098-48b7-86ce-a3914e8e6f82" alt="level4">
  <br>
  <br>

This exercise introduces the **router**. The router is used to link multiple networks together. It does so with the use of multiple interfaces (_Interface R1_, _Interface R2_, and _Interface R3_ in this example).
<br>
<br>

**1.** Since none of the masks on _Interface B1_, _Interface A1_, and _Interface R1_ are entered, we are free to choose our own subnet mask. A mask of **/24** is ideal as it leaves us with the entire 4th byte for the host address, and does not require binary calculations to find the range of possible host addresses.
<br>
<br>
The IP address of _Interface B1_ and _Interface R1_ must have the same network address as the IP address of _Interface A1_. With a subnet of _/24_, the possible range is:

  <center>

```
85.17.5.0 - 85.17.5.255
```

  </center>
  Excluding the network address and the broadcast address.
  <br>
  <br>

Note that we did not interact with the router _Interface R2_ and _Interface R3_, since none of our communications had to reach these sides of the router.

</br>

</details>

---

<details>
  <summary>Level 5</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/d2cb2a2b-818a-49b6-96cc-32a9549e64da" alt="level5">
  <br>
  <br>

This level introduces **routes**. A route contains 2 fields, the first one is the **destination** of outbound packets, the second one is the **next hop** of the packets.
<br>

The **destination** _default_ is equivalent to _0.0.0.0/0_, which will send the packets indiscriminately to the first network address it encounters. A destination address of _122.3.5.3/24_ would send the packets to the network _122.3.5.0_.

  <br>
  The **next hop** is the IP address of the next  router (or internet) interface to which the interface of the current machine must send its packets. 
  <br>
  <br>

**1.** _Client A_ only has 1 route through which it can send its packets. There is no use specifying a numbered destination. The destination _default_ will send the packets to the only path available.
<br>
<br>
The next hop address must be the IP address of the next router's interface on the packets' way. The next interface is _Interface R1_, with the IP address of _54.117.30.126_. Note that the next interface is not _Interface A1_, since this is the sender's own interface.

</br>

</details>

---

<details>
  <summary>Level 6</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/dc7a9084-3692-4eea-9ffd-695c6ea99278" alt="level6">
  <br>
  <br>

This level introduces the **internet**. The internet behaves like a router. However, if an interface is connected directly or indirectly to the internet, it **cannot** have an IP address in the following reserved private IP ranges:

```
192.168.0.0 - 192.168.255.255 (65,536 IP addresses)
172.16.0.0 - 172.31.255.255   (1,048,576 IP addresses)
10.0.0.0 - 10.255.255.255     (16,777,216 IP addresses)
```

**1.** The **next hop** of the internet is already entered, and matches the IP address of the _Interface R2_. Therefore we only need to bother with the destination of the internet.
<br>
<br>
The internet must send its packets to _Client A_. To do so, the internet's destination must match the network address of _Client A_. Let's find the network address of _Client A_:
<br>
_Client A_'s mask is _255.255.255.128_, which is equivalent to _/25_. This means that the first 25 bits of its IP address are its network address. We know then that the first 3 bytes (24 bits) of its IP address make part of its network address:

  <center>

```
40.178.145.?
```

  </center>

We now only need to find out if the 25th bit is a 1 or a 0.
<br>
If we convert the number 227 to binary, we get `11100011`. The first digit, which corresponds to the 25th bit, is a 1. Since only the 25th bit is part of the network address and not the remaining 7 bits, we get `10000000` for the last byte of the network address, which is 128 in decimal.
<br>
<br>
The full network address is:

  <center>

```
40.178.145.128
```

  </center>

With a range of _40.178.145.129 - 40.178.145.254_ for its host addresses.
<br>
<br>
We can now put this address of **40.178.145.128** in the Internet destination. The **/25** following the destination address represents the mask applied to its address.
<br>
<br>
A destination of _40.178.145.227/25_ is equivalent to the destination address _40.178.145.128/25_, since the mask of _/25_ will turn all the bits after the 25th to 0 to get the destination's network address.

</br>

</details>

---

<details>
  <summary>Level 7</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/de397d14-f928-4910-b103-b0734908f478" alt="level7">
  <br>
  <br>

This level introduces the concept of **overlaps**. The range of IP addresses of a network must not overlap the range of IP addresses of a separate network. Networks are separated by routers.
<br>
<br>

**1.** We have 3 separate networks:
<br>

1. Between _Client A_ and _Router R1_.
2. Between _Router R1_ and _Router R2_.
3. Between _Router R2_ and _Client C_.

For _Interface A1_, we cannot choose our IP address freely since the IP of _Interface R11_ is already entered. Also, if we give it a mask of _/24_, the IP address range will overlap with the range of _Interface R12_, which is already entered. They would both be in the range of _93.198.14.0 - 93.198.14.255_.
<br>
<br>

Since we need addresses for 3 separate networks, it is convenient to split the last bytes of the address into 4 or more address ranges. We do this by using a mask of _/26_ or higher. The mask of _/28_ for example will give us 16 ranges, from which we use the following 3:

```
93.198.14.1 - 93.198.14.14    (Client A to Router R1)
93.198.14.65 - 93.198.14.78   (Router R1 to Router R2)
93.198.14.241 - 93.198.14.254 (Router R2 to Client C)
```

To calculate the possible ranges of a mask:
<br>
[Calculate IP/Subnet](https://www.calculator.net/ip-subnet-calculator.html)

</br>

</details>

---

<details>
  <summary>Level 8</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/e06e41ca-26cf-4db3-a1da-77308609dd42" alt="level8">
  <br>
  <br>

**1.** The hosts _Client C_ and _Client D_ will send packets to the internet, then the internet will respond by sending packets all the way back to the initial sender. To send these packets, the internet uses the destination _49.175.13.0/26_ to send the packets to the networks in the range of `49.175.13.0 - 49.175.13.63`.
<br>
<br>
All the receiving networks must be in this range, without overlapping each other.
<br>
<br>

**2.** On _Interface R23_ and _Interface R22_ we use the mask _255.255.255.240_ (or _/28_), to conveniently split the range of _/26_ from the destination address, into 4 separate ranges. This separation of 4 is necessary since we have the following 3 networks that must not overlap:
<br>

1. _Router R1_ to _Router R2_.
2. _Router R2_ to _Client C_.
3. _Router R2_ to _Client D_.

Each of these networks can then be attributed one of the following IP ranges with a mask of _/28_:

```
49.175.13.0 - 49.175.13.15
49.175.13.16 - 49.175.13.31
49.175.13.32 - 49.175.13.47
49.175.13.48 - 49.175.13.63
```

Note that the network address (first) and the broadcast address (last) must be excluded from each range.
<br>
<br>

**3.** The destination and next hop for the internet are already entered. We only need to enter the next hop for the _Router R2_, which is the IP on the _Interface R21_.

</br>

</details>

---

<details>
  <summary>Level 9</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/0c8eb303-c1a9-404d-8682-db2f88ae8d36" alt="level9">
  <br>
  <br>

This level is quite straightforward since the internet does not initially send its packets to a specific network. Therefore, the separate networks do not need to share a common address range. I would suggest simply following the 6 goals of the level one by one until the level is completed.
<br>
<br>
Remember not to use the network addresses from the reserved private IP ranges.
<br>
<br>

**1.** **Goal 3** states that we must connect _meson_ with the _internet_. The _internet_ will then have to respond to _meson_, so we enter _meson's_ network address in the _internet's_ destination.
<br>
<br>
**Goal 6** states that we must connect _cation_ with the _internet_, so we enter _cation's_ network address in the _internet's_ destination.
<br>
<br>
It is normal to have an empty field for the 3rd destination of the _internet_, and in _Router R1's_ destination. Not all fields of the routing tables need to be filled.

</br>

</details>

---

<details>
  <summary>Level 10</summary>
  <br>
  <img src="https://github.com/Fartomy/42-Kickoff/assets/58911876/d54c692e-6a5f-4c2f-bead-9686e95dd080" alt="level10">
  <br>
  <br>

At this level, there are 4 different networks:
<br>

1. _Router R1_ to _Switch S1_
2. _Router R1_ to _Router R2_
3. _Router R2_ to _Client H4_
4. _Router R2_ to _Client H3_
   <br>

**1.** The internet must be able to send its packets to all the hosts, so its destination must cover the range of networks of all the hosts.
<br>
<br>

_Interface R11_ and _Interface R13_ already have an IP address entered. This IP address only differs in its last byte. _Interface R11_ has for last byte **1**, and _Interface R13_ has for last byte **254**. To cover this wide range to IP addresses, we take a mask of **/24** for the _internet's_ destination. This destination will cover a range of `70.101.30.0 - 70.101.30.255`.

  <br>
  <br>

**2.** When choosing the IP addresses, we must make sure of 2 things:
<br>

1. The IP address is covered by the _internet_ destination.
2. The IP address range of the various networks does not overlap.
   <br>

With the IP addresses already entered (greyed out), let's examine the ranges covered by the various networks:
<br>

1. _Router R1_ to _Switch S1_ - Covers the range **70.101.30.0 - 70.101.30.127** (mask /25).
2. _Router R2_ to _Client H4_ - Covers the range **70.101.30.128 - 70.101.30.191** (mask /26).
3. _Router R1_ to _Router R2_ - Covers the range **70.101.30.252 - 70.101.30.255** (mask /30).
4. _Router R2_ to _Client H3_ - ??? (mask ???).

The only IP addresses left for the network "Router R2 to Client H3" are **70.101.30.192 - 70.101.30.251**. We can pick any mask that will let us take 2 IP addresses from that range to put in _Interface R22_ and _Interface R31_.

</br>

</details>

---

## About of Net Practice Project Files Errors

> [!WARNING]
> ### Problem 1
> When you try to run the **Net Practice** file on your computer, if some sections are missing (for example, the _Check_, _Get My Config_ buttons in the upper blue area and _error logs in the lower right corner_),
> you are probably encountering an error in the `show.js` file. To find out, open any `levelX.html` file in the browser and verify whether there is an error by opening it in **_Inspect_** mode.
> You may be getting an error. To solve the examples I mentioned above, I solved the problem by finding the following solution for the `g_eval_lvls` variable in the `show.js` file I just mentioned.
> 
> ```
> // Add the following lines to the following function in "show.js" and try again:
>
> function my_console_log(str)
> {
>   // console.log(str);
>   if(!g_eval_lvls)
>   {
>     g_eval_lvls = [];
>   }
> }
> ```
> ### Problem 2
> Although the required input is provided to the desired location on the `index.html` page,
> the reason why it creates problems in level advancement is that the `g_my_login` variable in the `show.js` file does not hold the value you give.
> I did not personally investigate in detail why it did not store the value. The reason was that the problem was solved when I opened index.html in a different browser and advanced the section.
>
> ### Quirks Mode Warning Problem
>
> This is not exactly a problem, but I felt good when he solved it. The reason is that the solution is simple. Of course, if you're in that mood (Quirk).
> The solution is written in the console tab when in inspection mode.

## 🧠 Resources
1. [TCP/IP Adressing](https://www.techtarget.com/searchnetworking/definition/TCP-IP)
2. [OSI Model](https://www.geeksforgeeks.org/open-systems-interconnection-model-osi/)
   - [MAC Adress](https://www.geeksforgeeks.org/mac-address-in-computer-network/)
3. [Subnet Mask Table Cheat Sheet 1](https://www.aelius.com/njh/subnet_sheet.html)
6. [Subnet Mask Table Cheat Sheet 2](https://subnet.ninja/subnet-cheat-sheet/)
4. [Subnet Mask Cheat Sheet 1](https://www.freecodecamp.org/news/subnet-cheat-sheet-24-subnet-mask-30-26-27-29-and-other-ip-address-cidr-network-references/)
5. [Subnet Mask Cheat Sheet 2](https://www.geeksforgeeks.org/subnet-cheat-sheet/)
6. [Subnet Mask Video 1](https://m.youtube.com/watch?v=oZGZRtaGyG86)
7. [Subnet Mask Video 2](https://m.youtube.com/watch?v=s_Ntt6eTn94)
8. [Perfect Document of Net Practice](https://github.com/lpaube/NetPractice)
9. [IP-Subnet Calculator](https://www.calculator.net/ip-subnet-calculator.html)
10. [ChatGPT](https://chat.openai.com/)
