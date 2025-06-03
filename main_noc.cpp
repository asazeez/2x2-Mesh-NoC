// main.cpp
#include "systemc.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "packet.h"
#include "source.h"
#include "sink.h"
#include "router.h"


int sc_main(int argc, char *argv[])
{
	sc_signal<packet> si_source[16];
	sc_signal<packet> si_input[16];
	sc_signal<packet> si_zero[64];
	sc_signal<packet> si_sink[16];
	sc_signal<packet> si_output[64];
	sc_signal<bool>  si_ack_src[64];
	sc_signal<bool>  si_ack_sink[16],si_ack_in[64];
	sc_signal<bool>  si_ack_zero[64];
	sc_signal<sc_uint<4> > id0,id1, id2, id3, id4,id5, id6, id7,id8,id9, id10, id11,id12,id13, id14, id15;
	sc_signal<int> sink_input;
	sc_signal<sc_uint<4> > source_input;

	int i,j;
	int source_uniform[5] = {0, 3, 7, 2};
	int sink_uniform[5] = 	{15, 4, 12, 14};

	sc_clock s_clock("S_CLOCK", 125, SC_NS, 0.5, 0.0, SC_NS); // source clock
	//sc_clock s_clock("S_CLOCK", 5, SC_NS, 0.5, 10.0, SC_NS); // source clk = router clk
	sc_clock r_clock("R_CLOCK", 5, SC_NS, 0.5, 10.0, SC_NS);	// router clock
	sc_clock d_clock("D_CLOCK", 5, SC_NS, 0.5, 10.0, SC_NS);	// destination clock
	
	// Module instiatiations follow
	// Note that modules can be connected by hooking up ports 
	// to signals by name or by using a positional notation
	
	source source0("source0");
	source0(si_source[0], id0, si_ack_src[0], s_clock, sink_input,source_input);
	
    source source1("source1");
	source1(si_source[1], id1, si_ack_src[1], s_clock, sink_input,source_input);

	source source2("source2");
	source2(si_source[2], id2, si_ack_src[2], s_clock, sink_input,source_input);
	
	source source3("source3");
	source3(si_source[3], id3, si_ack_src[3], s_clock, sink_input,source_input);

	source source4("source4");
	source4(si_source[4], id4, si_ack_src[4], s_clock, sink_input,source_input);
	
    source source5("source5");
	source5(si_source[5], id5, si_ack_src[5], s_clock, sink_input,source_input);

	source source6("source6");
	source6(si_source[6], id6, si_ack_src[6], s_clock, sink_input,source_input);
	
	source source7("source7");
	source7(si_source[7], id7, si_ack_src[7], s_clock, sink_input,source_input);

	source source8("source8");
	source8(si_source[8], id8, si_ack_src[8], s_clock, sink_input,source_input);
	
    source source9("source9");
	source9(si_source[9], id9, si_ack_src[9], s_clock, sink_input,source_input);

	source source10("source10");
	source10(si_source[10], id10, si_ack_src[10], s_clock, sink_input,source_input);
	
	source source11("source11");
	source11(si_source[11], id11, si_ack_src[11], s_clock, sink_input,source_input);

	source source12("source12");
	source12(si_source[12], id12, si_ack_src[12], s_clock, sink_input,source_input);
	
    source source13("source13");
	source13(si_source[13], id13, si_ack_src[13], s_clock, sink_input,source_input);

	source source14("source14");
	source14(si_source[14], id14, si_ack_src[14], s_clock, sink_input,source_input);
	
	source source15("source15");
	source15(si_source[15], id15, si_ack_src[15], s_clock, sink_input,source_input);

	router router0("router0");

	router0.in0(si_source[0]); //source 0
	router0.in1(si_zero[1]);
	router0.in2(si_output[2]);  //router 1
	router0.in3(si_output[12]); //router 4
	router0.in4(si_zero[2]);

	router0.router_id(id0);

	router0.out0(si_sink[0]); 
	router0.out2(si_output[0]);
	router0.out3(si_output[1]);
	router0.out1(si_zero[3]);
	router0.out4(si_zero[4]);

	router0.inack0(si_ack_sink[0]); //sink 0
	router0.inack1(si_ack_zero[1]); 
	router0.inack2(si_ack_in[2]); //router 1
	router0.inack3(si_ack_in[12]);
	router0.inack4(si_ack_zero[2]);

	router0.outack0(si_ack_src[0]);
	router0.outack2(si_ack_in[0]);
	router0.outack3(si_ack_in[1]);
	router0.outack1(si_ack_zero[3]);
	router0.outack4(si_ack_zero[4]);

	router0.rclk(r_clock);

	router router1("router1");
	
	router1.in0(si_source[1]); //source 1
	router1.in1(si_output[0]); //router 0
	router1.in2(si_output[7]); //router 2
	router1.in3(si_output[16]); //router 5
	router1.in4(si_zero[5]);
	
	router1.router_id(id1);

	router1.out0(si_sink[1]); //sink 1
	router1.out4(si_output[2]);
	router1.out3(si_output[3]);
	router1.out2(si_output[4]);
	router1.out1(si_zero[6]);

	router1.inack0(si_ack_sink[1]); //sink 1
	router1.inack1(si_ack_in[0]); //router 0
	router1.inack2(si_ack_in[7]); //router 2
	router1.inack3(si_ack_in[16]); //router 5
	router1.inack4(si_ack_zero[5]);

	router1.outack0(si_ack_src[1]);
	router1.outack4(si_ack_in[2]);
	router1.outack3(si_ack_in[3]);
	router1.outack2(si_ack_in[4]);
	router1.outack1(si_ack_zero[6]);

	router1.rclk(r_clock);

	router router2("router2");

	router2.in0(si_source[2]); //source 2
	router2.in1(si_output[4]); //router 1
	router2.in2(si_output[9]); //router 3
	router2.in3(si_output[17]); //router 6
	router2.in4(si_zero[7]);

	router2.router_id(id2);

	router2.out0(si_sink[2]);
	router2.out1(si_zero[19]);
	router2.out2(si_output[5]);
	router2.out3(si_output[6]);
	router2.out4(si_output[7]);
	
	router2.inack0(si_ack_sink[2]); //sink 2
	router2.inack1(si_ack_in[4]); //router 1
	router2.inack2(si_ack_in[9]); //router 3
	router2.inack3(si_ack_in[17]); //router 6
	router2.inack4(si_ack_zero[7]);
	
	router2.outack0(si_ack_src[2]);
	router2.outack1(si_ack_zero[19]);
	router2.outack2(si_ack_in[5]);
	router2.outack3(si_ack_in[6]);
	router2.outack4(si_ack_in[7]);
	
	router2.rclk(r_clock);

	router router3("router3");

	router3.in0(si_source[3]); //source 3
	router3.in1(si_output[5]); //router 2
	router3.in2(si_output[21]); //router 7
	router3.in3(si_zero[8]);
	router3.in4(si_zero[9]);

	router3.router_id(id3);

	router3.out0(si_sink[3]);
	router3.out3(si_output[8]);
	router3.out4(si_output[9]);
	router3.out2(si_zero[20]);
	router3.out1(si_zero[21]);

	router3.inack0(si_ack_sink[3]); //sink 3
	router3.inack1(si_ack_in[5]); //router 2
	router3.inack2(si_ack_in[21]); //router 7
	router3.inack3(si_ack_zero[8]);
	router3.inack4(si_ack_zero[9]);

	router3.outack0(si_ack_src[3]);
	router3.outack3(si_ack_in[8]);
	router3.outack4(si_ack_in[9]);
	router3.outack2(si_ack_zero[20]);
	router3.outack1(si_ack_zero[21]);

	router3.rclk(r_clock);

	router router4("router4");
	
	router4.in0(si_source[4]); //source 4
	router4.in1(si_output[1]); //router 0
	router4.in2(si_output[13]); //router 5
	router4.in3(si_output[26]); //router 8
	router4.in4(si_zero[10]);

	router4.router_id(id4);

	router4.out0(si_sink[4]);
	router4.out2(si_output[10]);
	router4.out3(si_output[11]);
	router4.out1(si_output[12]);
	router4.out4(si_zero[22]);

	router4.inack0(si_ack_sink[4]); //sink 4
	router4.inack1(si_ack_in[1]); //router 0
	router4.inack2(si_ack_in[13]); //router 5
	router4.inack3(si_ack_in[26]); //router 8
	router4.inack4(si_ack_zero[10]);

	router4.outack0(si_ack_src[4]);
	router4.outack2(si_ack_in[10]);
	router4.outack3(si_ack_in[11]);
	router4.outack1(si_ack_in[12]);
	router4.outack4(si_ack_zero[22]);

	router4.rclk(r_clock);

	router router5("router5");

	router5.in0(si_source[5]); //source 5
	router5.in1(si_output[3]); //router 1
	router5.in2(si_output[10]); //router 4
	router5.in3(si_output[20]); //router 6
	router5.in4(si_output[30]); //router 9
	

	router5.router_id(id5);

	router5.out0(si_sink[5]);
	router5.out4(si_output[13]);
	router5.out3(si_output[14]);
	router5.out2(si_output[15]);
	router5.out1(si_output[16]);

	router5.inack0(si_ack_sink[5]); //sink 5
	router5.inack1(si_ack_in[3]); //router 1
	router5.inack2(si_ack_in[10]); //router 4
	router5.inack3(si_ack_in[20]); //router6
	router5.inack4(si_ack_in[30]); //router 9

	router5.outack0(si_ack_src[5]);
	router5.outack4(si_ack_in[13]);
	router5.outack3(si_ack_in[14]);
	router5.outack2(si_ack_in[15]);
	router5.outack1(si_ack_in[16]);

	router5.rclk(r_clock);

	router router6("router6");

	router6.in0(si_source[6]);//souce 6
	router6.in1(si_output[6]); //router 2
	router6.in2(si_output[15]); //router 7
	router6.in3(si_output[22]); //router 10
	router6.in4(si_output[31]); //router 5
	
	router6.router_id(id6);

	router6.out0(si_sink[6]); 
	router6.out1(si_output[17]); 
	router6.out2(si_output[18]); 
	router6.out3(si_output[19]); 
	router6.out4(si_output[20]); 
	
	router6.inack0(si_ack_sink[6]); 
	router6.inack1(si_ack_in[6]); 
	router6.inack2(si_ack_in[15]); 
	router6.inack3(si_ack_in[22]); 
	router6.inack4(si_ack_in[31]);
	
	router6.outack0(si_ack_src[6]); //sink 6
	router6.outack1(si_ack_in[17]); //router 2
	router6.outack2(si_ack_in[18]); //router 7
	router6.outack3(si_ack_in[19]); //router 10
	router6.outack4(si_ack_in[20]); //router 5	

	router6.rclk(r_clock);

	router router7("router7");

	router7.in0(si_source[7]); //source 7
	router7.in1(si_output[8]); //router 3
	router7.in2(si_output[18]); //router 6
	router7.in3(si_output[35]); //router 11
	router7.in4(si_zero[11]);

	router7.router_id(id7);

	router7.out0(si_sink[7]);
	router7.out1(si_output[21]);
	router7.out4(si_output[22]);
	router7.out3(si_output[23]);
	router7.out2(si_zero[23]);
	
	router7.inack0(si_ack_sink[7]); //sink 7
	router7.inack1(si_ack_in[8]); //router 4
	router7.inack2(si_ack_in[18]); //router 6
	router7.inack3(si_ack_in[35]); //router 11
	router7.inack4(si_ack_zero[11]);

	router7.outack0(si_ack_src[7]);
	router7.outack1(si_ack_in[21]);
	router7.outack4(si_ack_in[22]);
	router7.outack3(si_ack_in[23]);
	router7.outack2(si_ack_zero[23]);

	router7.rclk(r_clock);

	router router8("router8");

	router8.in0(si_source[8]); //source 8
	router8.in1(si_output[11]); //router 4
	router8.in2(si_output[27]); //router 9
	router8.in3(si_output[38]); //router 12
	router8.in4(si_zero[12]);

	router8.router_id(id8);

	router8.out0(si_sink[8]);
	router8.out2(si_output[24]);
	router8.out3(si_output[25]);
	router8.out1(si_output[26]);
	router8.out4(si_zero[24]);

	router8.inack0(si_ack_sink[8]); //sink 8
	router8.inack1(si_ack_in[11]); //router 4
	router8.inack2(si_ack_in[27]); //router 9
	router8.inack3(si_ack_in[38]); //router 12
	router8.inack4(si_ack_zero[12]);

	router8.outack0(si_ack_src[8]);
	router8.outack2(si_ack_in[24]);
	router8.outack3(si_ack_in[25]);
	router8.outack1(si_ack_in[26]);
	router8.outack4(si_ack_zero[24]);

	router8.rclk(r_clock);

	router router9("router9");

	router9.in0(si_source[9]); //source 9
	router9.in1(si_output[14]); //router 5
	router9.in2(si_output[24]); //router 8
	router9.in3(si_output[34]); //router 10
	router9.in4(si_output[41]); //router 13

	router9.router_id(id9);

	router9.out0(si_sink[9]);
	router9.out4(si_output[27]);
	router9.out3(si_output[28]);
	router9.out2(si_output[29]);
	router9.out1(si_output[30]);

	router9.inack0(si_ack_sink[9]); //sink 9
	router9.inack1(si_ack_in[14]); //router 5
	router9.inack2(si_ack_in[24]); //router 8
	router9.inack3(si_ack_in[34]); //router 10
	router9.inack4(si_ack_in[41]); //router 13

	router9.outack0(si_ack_src[9]);
	router9.outack4(si_ack_in[27]);
	router9.outack3(si_ack_in[28]);
	router9.outack2(si_ack_in[29]);
	router9.outack1(si_ack_in[30]);

	router9.rclk(r_clock);

	router router10("router10");
	router10.in0(si_source[10]);//source 10
	router10.in1(si_output[19]); //router 6
	router10.in2(si_output[29]); //router 11
	router10.in3(si_output[36]); //router 14
	router10.in4(si_output[43]); //router 9
	
	router10.router_id(id10);

	router10.out0(si_sink[10]); 
	router10.out1(si_output[31]); 
	router10.out2(si_output[32]); 
	router10.out3(si_output[33]); 
	router10.out4(si_output[34]); 
	
	router10.inack0(si_ack_sink[10]); 
	router10.inack1(si_ack_in[19]);
	router10.inack2(si_ack_in[29]);
	router10.inack3(si_ack_in[36]);
	router10.inack4(si_ack_in[43]);
	
	router10.outack0(si_ack_src[10]); //sink 10
	router10.outack1(si_ack_in[31]); //router 6
	router10.outack2(si_ack_in[32]); //router 11
	router10.outack3(si_ack_in[33]); //router 14
	router10.outack4(si_ack_in[34]); //router 9
	
	router10.rclk(r_clock);

	router router11("router11");

	router11.in0(si_source[11]); //source 11
	router11.in1(si_output[23]); //router 7
	router11.in2(si_output[32]); //router 10
	router11.in3(si_output[46]); //router 15
	router11.in4(si_zero[13]);

	router11.router_id(id11);

	router11.out0(si_sink[11]);
	router11.out1(si_output[35]);
	router11.out4(si_output[36]);
	router11.out3(si_output[37]);
	router11.out2(si_zero[25]);
	
 	router11.inack0(si_ack_sink[11]); //sink 11
	router11.inack1(si_ack_in[23]); //router 7
	router11.inack2(si_ack_in[32]); //router 10
	router11.inack3(si_ack_in[46]); //router 15
	router11.inack4(si_ack_zero[13]);

	router11.outack0(si_ack_src[11]);
	router11.outack1(si_ack_in[35]);
	router11.outack4(si_ack_in[36]);
	router11.outack3(si_ack_in[37]);
	router11.outack2(si_ack_zero[25]);

	router11.rclk(r_clock);

	router router12("router12");

	router12.in0(si_source[12]); //source 12
	router12.in1(si_output[25]); //router 8
	router12.in2(si_output[40]); //router 13
	router12.in3(si_zero[14]);
	router12.in4(si_zero[15]);

	router12.router_id(id12);

	router12.out0(si_sink[12]);
	router12.out1(si_output[38]);
	router12.out2(si_output[39]);
	router12.out3(si_zero[26]);
	router12.out4(si_zero[27]);

	router12.inack0(si_ack_sink[12]); //sink 12
	router12.inack1(si_ack_in[25]); //router 8
	router12.inack2(si_ack_in[40]); //router 13
	router12.inack3(si_ack_zero[14]);
	router12.inack4(si_ack_zero[15]);

	router12.outack0(si_ack_src[12]);
	router12.outack1(si_ack_in[38]);
	router12.outack2(si_ack_in[39]);
	router12.outack3(si_ack_zero[26]);
	router12.outack4(si_ack_zero[27]);

	router12.rclk(r_clock);

	router router13("router13");

	router13.in0(si_source[13]); //source 13
	router13.in1(si_output[28]); //router 9
	router13.in2(si_output[39]); //router 12
	router13.in3(si_output[45]); //router 14
	router13.in4(si_zero[16]);
	
	router13.router_id(id13);

	router13.out0(si_sink[13]);
	router13.out4(si_output[40]);
	router13.out1(si_output[41]);
	router13.out2(si_output[42]);
	router13.out3(si_zero[28]);

	router13.inack0(si_ack_sink[13]); //sink 13
	router13.inack1(si_ack_in[28]); //router 9
	router13.inack2(si_ack_in[39]); //router 12
	router13.inack3(si_ack_in[45]); //router 14
	router13.inack4(si_ack_zero[16]);

	router13.outack0(si_ack_src[13]);
	router13.outack4(si_ack_in[40]);
	router13.outack1(si_ack_in[41]);
	router13.outack2(si_ack_in[42]);
	router13.outack3(si_ack_zero[28]);

	router13.rclk(r_clock);

	router router14("router14");

	router14.in0(si_source[14]); //source 14
	router14.in1(si_output[33]); //router 10
	router14.in2(si_output[42]); //router 13
	router14.in3(si_output[47]); //router 15
	router14.in4(si_zero[17]);
	
	router14.router_id(id14);

	router14.out0(si_sink[14]);
	router14.out1(si_output[43]);
	router14.out2(si_output[44]);
	router14.out4(si_output[45]);
	router14.out3(si_zero[29]);
	
	router14.inack0(si_ack_sink[14]); //sink 14
	router14.inack1(si_ack_in[33]); //router 10
	router14.inack2(si_ack_in[42]); //router 13
	router14.inack3(si_ack_in[47]); //router 15
	router14.inack4(si_ack_zero[17]);
	
	router14.outack0(si_ack_src[14]);
	router14.outack1(si_ack_in[43]);
	router14.outack2(si_ack_in[44]);
	router14.outack4(si_ack_in[45]);
	router14.outack3(si_ack_zero[29]);

	router14.rclk(r_clock);

	router router15("router15");

	router15.in0(si_source[15]); //source 15
	router15.in1(si_output[37]); //router 11
	router15.in2(si_output[44]); //router 14
	router15.in3(si_zero[18]);
	router15.in4(si_zero[19]);

	router15.router_id(id15);

	router15.out0(si_sink[15]);
	router15.out1(si_output[46]);
	router15.out4(si_output[47]);
	router15.out2(si_zero[30]);
	router15.out3(si_zero[31]);
	
	router15.inack0(si_ack_sink[15]); //sink 15
	router15.inack1(si_ack_in[37]); //router 11
	router15.inack2(si_ack_in[44]); //router 14
	router15.inack3(si_ack_zero[18]);
	router15.inack4(si_ack_zero[19]);
	
	router15.outack0(si_ack_src[15]);
	router15.outack1(si_ack_in[46]);
	router15.outack4(si_ack_in[47]);
	router15.outack2(si_ack_zero[30]);
	router15.outack3(si_ack_zero[31]);

	router15.rclk(r_clock);

	sink sink0("sink0");
	sink0(si_sink[0], si_ack_sink[0], id0, d_clock);

	sink sink1("sink1");
	sink1(si_sink[1], si_ack_sink[1], id1, d_clock);

	sink sink2("sink2");
	sink2(si_sink[2], si_ack_sink[2], id2, d_clock);
	
	sink sink3("sink3");
	sink3(si_sink[3], si_ack_sink[3], id3, d_clock);

	sink sink4("sink4");
	sink4(si_sink[4], si_ack_sink[4], id4, d_clock);

	sink sink5("sink5");
	sink5(si_sink[5], si_ack_sink[5], id5, d_clock);

	sink sink6("sink6");
	sink6(si_sink[6], si_ack_sink[6], id6, d_clock);
	
	sink sink7("sink7");
	sink7(si_sink[7], si_ack_sink[7], id7, d_clock);

	sink sink8("sink8");
	sink8(si_sink[8], si_ack_sink[8], id8, d_clock);

	sink sink9("sink9");
	sink9(si_sink[9], si_ack_sink[9], id9, d_clock);

	sink sink10("sink10");
	sink10(si_sink[10], si_ack_sink[10], id10, d_clock);

	sink sink11("sink11");
	sink11(si_sink[11], si_ack_sink[11], id11, d_clock);

	sink sink12("sink12");
	sink12(si_sink[12], si_ack_sink[12], id12, d_clock);

	sink sink13("sink13");
	sink13(si_sink[13], si_ack_sink[13], id13, d_clock);

	sink sink14("sink14");
	sink14(si_sink[14], si_ack_sink[14], id14, d_clock);
		
	sink sink15("sink15");
	sink15(si_sink[15], si_ack_sink[15], id15, d_clock);
	

//sc_start(0, SC_NS);
  // tracing:
	// trace file creation
	sc_trace_file *tf = sc_create_vcd_trace_file("graph");
	// External Signals
	sc_trace(tf, s_clock, "s_clock");
	sc_trace(tf, d_clock, "d_clock");
	sc_trace(tf, r_clock, "r_clock");
	sc_trace(tf, si_source[0], "si_source[0]");
	sc_trace(tf, si_source[1], "si_source[1]");
	sc_trace(tf, si_source[2], "si_source[2]");
	sc_trace(tf, si_source[3], "si_source[3]");
	sc_trace(tf, si_source[4], "si_source[4]");
	sc_trace(tf, si_source[5], "si_source[5]");
	sc_trace(tf, si_source[6], "si_source[6]");
	sc_trace(tf, si_source[7], "si_source[7]");
	sc_trace(tf, si_source[8], "si_source[8]");
	sc_trace(tf, si_source[9], "si_source[9]");
	sc_trace(tf, si_source[10], "si_source[10]");
	sc_trace(tf, si_source[11], "si_source[11]");
	sc_trace(tf, si_source[12], "si_source[12]");
	sc_trace(tf, si_source[13], "si_source[13]");
	sc_trace(tf, si_source[14], "si_source[14]");
	sc_trace(tf, si_source[15], "si_source[15]");

	sc_trace(tf, si_sink[0], "si_sink[0]");
	sc_trace(tf, si_sink[1], "si_sink[1]");
	sc_trace(tf, si_sink[2], "si_sink[2]");
	sc_trace(tf, si_sink[3], "si_sink[3]");
	sc_trace(tf, si_sink[4], "si_sink[4]");
	sc_trace(tf, si_sink[5], "si_sink[5]");
	sc_trace(tf, si_sink[6], "si_sink[6]");
	sc_trace(tf, si_sink[7], "si_sink[7]");
	sc_trace(tf, si_sink[8], "si_sink[8]");
	sc_trace(tf, si_sink[9], "si_sink[9]");
	sc_trace(tf, si_sink[10], "si_sink[10]");
	sc_trace(tf, si_sink[11], "si_sink[11]");
	sc_trace(tf, si_sink[12], "si_sink[12]");
	sc_trace(tf, si_sink[13], "si_sink[13]");
	sc_trace(tf, si_sink[14], "si_sink[14]");
	sc_trace(tf, si_sink[15], "si_sink[15]");
	
	id0.write(0);
	id1.write(1);
	id2.write(2);
	id3.write(3);
	id4.write(4);
	id5.write(5);
	id6.write(6);
	id7.write(7);
	id8.write(8);
	id9.write(9);
	id10.write(10);
	id11.write(11);
	id12.write(12);
	id13.write(13);
	id14.write(14);
	id15.write(15);

	/**cout<< "Enter source node (0 to 15): ";
	cin >> i;
	cout<<"Enter sink node (0 to 15): ";
	cin >> j;**/


	cout << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl << " 4X4 mesh NOC simulator containing 2 5x5 Wormhole router " << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "This is the simulation of a 4x4 Wormhole router.  " << endl; 
	cout << "We assume the router has 5 input/output ports, with 4 buffers per input port " << endl;
	cout << "and each flit has 21 bits width " << endl;
	cout << "  Press \"Return\" key to start the simulation..." << endl << endl;

	getchar();

	int k;
	cout << endl << endl << "------------------------------Uniform Pattern-------------------------------------------" << endl;
	for (k=0; k<15; k++){
		i = k;
		j = k+1;

		sink_input.write(j);
		source_input.write(i);

		sc_start(10*125+124,SC_NS); // during [(10*125)+124] ns 10 packets will be sent and received 
		
		cout << endl << endl << "-------------------------------------------------------------------------------" << endl;
		cout << "End of switch operation..." << endl;
		if(i==0)cout << "Total number of packets sent: " <<  source0.pkt_snt<< endl;
		if(j==0)cout << "Total number of packets received: " <<  sink0.pkt_recv<< endl;
		if(i==1)cout << "Total number of packets sent: " <<  source1.pkt_snt<< endl;
		if(j==1)cout << "Total number of packets received: " <<  sink1.pkt_recv<< endl;
		if(i==2)cout << "Total number of packets sent: " <<  source2.pkt_snt<< endl;
		if(j==2)cout << "Total number of packets received: " <<  sink2.pkt_recv<< endl;
		if(i==3)cout << "Total number of packets sent: " <<  source3.pkt_snt<< endl;
		if(j==3)cout << "Total number of packets received: " <<  sink3.pkt_recv<< endl;

		if(i==4)cout << "Total number of packets sent: " <<  source4.pkt_snt<< endl;
		if(j==4)cout << "Total number of packets received: " <<  sink4.pkt_recv<< endl;
		if(i==5)cout << "Total number of packets sent: " <<  source5.pkt_snt<< endl;
		if(j==5)cout << "Total number of packets received: " <<  sink5.pkt_recv<< endl;
		if(i==6)cout << "Total number of packets sent: " <<  source6.pkt_snt<< endl;
		if(j==6)cout << "Total number of packets received: " <<  sink6.pkt_recv<< endl;
		if(i==7)cout << "Total number of packets sent: " <<  source7.pkt_snt<< endl;
		if(j==7)cout << "Total number of packets received: " <<  sink7.pkt_recv<< endl;

		if(i==8)cout << "Total number of packets sent: " <<  source8.pkt_snt<< endl;
		if(j==8)cout << "Total number of packets received: " <<  sink8.pkt_recv<< endl;
		if(i==9)cout << "Total number of packets sent: " <<  source9.pkt_snt<< endl;
		if(j==9)cout << "Total number of packets received: " <<  sink9.pkt_recv<< endl;
		if(i==10)cout << "Total number of packets sent: " <<  source10.pkt_snt<< endl;
		if(j==10)cout << "Total number of packets received: " <<  sink10.pkt_recv<< endl;
		if(i==11)cout << "Total number of packets sent: " <<  source11.pkt_snt<< endl;
		if(j==11)cout << "Total number of packets received: " <<  sink11.pkt_recv<< endl;

		if(i==12)cout << "Total number of packets sent: " <<  source12.pkt_snt<< endl;
		if(j==12)cout << "Total number of packets received: " <<  sink12.pkt_recv<< endl;
		if(i==13)cout << "Total number of packets sent: " <<  source13.pkt_snt<< endl;
		if(j==13)cout << "Total number of packets received: " <<  sink13.pkt_recv<< endl;
		if(i==14)cout << "Total number of packets sent: " <<  source14.pkt_snt<< endl;
		if(j==14)cout << "Total number of packets received: " <<  sink14.pkt_recv<< endl;
		if(i==15)cout << "Total number of packets sent: " <<  source15.pkt_snt<< endl;
		if(j==15)cout << "Total number of packets received: " <<  sink15.pkt_recv<< endl;

	}

	
	sc_close_vcd_trace_file(tf);


	cout << "-------------------------------------------------------------------------------" << endl;
    cout << "  Press \"Return\" key to end the simulation..." << endl << endl;
	getchar();
  	return 0;
}

