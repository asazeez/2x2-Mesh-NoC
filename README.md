# 4x4 Mesh NoC
4x4 Mesh NoC final projected completed for COE 838 (Systems-On-Chip Design).

## Abstract
This project focused on the implementation of a 4x4 mesh NoC using a modular and scalable design. In this design, the NoC simulator comprises of the source and sink modules with the routing achieved through the use of an arbiter, FIFOs, and crossbar switch. Since the packet routing is based on the routing algorithms, SystemC is used to model the routers and buffers to simulate NoC packet transmission. The system is verified using various communication patterns such as uniform and neighborhood.
<div align="center"><img src="https://github.com/user-attachments/assets/02a8e9d4-ba40-49a6-b162-ebe6eefd50cf" width="300"/></div>

## Design
### Source Module
The source module generates the synthetic packets that are sent through the network.The source generates packets using SC\_THREAD so that packets are injected into the network only on the positive edge of the clock

### Router
The router is responsible for directing the packet to the correct sink module. In this design, the router consists of the following submodules: FIFO, crossbar, and arbiter. The FIFO buffer module temporarily stores the incoming flit in the tail of the buffer. When a flit reaches the head of the FIFO, a request is sent to the arbiter module. The arbiter manages the routing and switching by controlling access to output ports and handling multiple requests for the same port. In this implementation, an XY routing scheme is used where first the X direction is determined by comparing the first two bits of the current router ID with the destination. Then the Y direction is determined by comparing last two bits. 

Once the arbiter determines that the requested output is free, it sends a grant signal to the FIFO, activating the read port. The flit is then sent to the input port of the crossbar module. The crossbar module reads in the address of the output port and sends the packet out of the router via that port.
<div align="center"><img src="https://github.com/user-attachments/assets/78512c7b-17e5-4ce4-a83f-f4dfb095ba2d" width="500"/></div>

### Sink Module
The packet is received by the sink module through its port and an acknowledgment is sent back to the router.

## Results
### Uniform Pattern
Receives all ten packets from source 0 to sink 15 to verify packets can be sent at opposite ends of the NoC.
<div align="center">
  <img src="https://github.com/user-attachments/assets/3bbf4b40-027b-4766-bd11-3fad513f7460" width="500"/>
</div>
<div align="center">
  <img src="https://github.com/user-attachments/assets/d779ed62-7f50-4caa-8698-44453a54d5df" width="500" style="margin: 10px;" />
</div>

### Neighbourhood Pattern
Packets can be delivered when tw nodes are neighbours in the X direction. In this case packets are sent from source 0 to sink 1.
<div align="center">
  <img src="https://github.com/user-attachments/assets/0fbd45ec-42c8-41bb-bb7c-790a94276f8f" width="500"/>
</div>
<div align="center">
  <img src="https://github.com/user-attachments/assets/e1b71611-d159-4aa5-b306-aa34e66797e1" width="500" style="margin: 10px;" />
</div>

## Conclusion
this project provided valuable experience in the design and implementation of NoCs and the use of SystemC to model hardware/software. 
