#ifndef DUML_H
#define DUML_H

// =======================================================================================================
class Duml{
	private:
		
		void  	CalcLength();								// Calculates length of the data field
		void 	CalcCRC8();									// Calculates CRC8 value of the DUML
		void 	CalcCRC8Sent();								// Calculates transmitted CRC8 value
		void 	CalcVersion();								// Calculates protocol version
		void 	CalcSenderID();								// Calculates sender ID
		void 	CalcSenderType();							// Calculates sender type
		void 	CalcReceiverID();							// Calculates receiver ID
		void 	CalcReceiverType();							// Calculates receiver type
		void 	CalcSeq();									// Calculates sequence value
		void 	CalcCMDSet();								// Calculates command set
		void 	CalcCMDID();								// Calculates command ID
		void 	CalcCMDType();								// Calculates command type
		void 	CalcIsNeedAck();							// Calculates ACK value
		void 	CalcCellVoltages();							// Calculates cell voltages
		void 	CalcBatteryState();							// Calculates battery parameters
				
		int 	DecodeBytes(int off, int len);				// Decode Byte string
		int 	HexSeq[2];
		
		static const int CRC8[];							// Initial CRC8 values
		static const int CRC16[];							// Initial CRC16 values
		static const int ZERO[]; 							// Array of zeros
		
		
	
	public:
				Duml();										// Constructor
				Duml(int buff[]);
		int 	*HexString;									// DUML string hex format
		int 	NC;											// Number of Cells (FPV:6, Avata:4)
		void 	init(int buff[]);							// Init object with DUML string (hex format)
		void 	Calc();										// Calc all DUML information
		void 	CalcCRC16();								// Calc checksum of the whole DUML message (CRC16)
		void 	CalcCRC16Sent();							// Writes the transmitted CRC16 checksum to object array Crc16Sent[2]
		bool  	CheckHeader();								// Calculates the checksum of the header and compares it with the transmitted checksum
		bool  	CheckDuml();								// Checks if the calculated checksum of the DUML is the same than the transmitted checksum
		int 	CalcData();									// Returns the length of the data field
		void 	SetSeq(int seq);							// Sets the sequence number of the DUML to seq
		void 	SetCapacity(int cap);						// Set the transmitted capacity to cap
		void 	SetDesignCapacity(int cap);					// Set the transmitted design capacity of the battery to cap
		void 	SetPercent(int prs);						// Set the transmitted remaining percentage to prs
		void 	Clear();									// Clears the DUML
		int 	CalcPing();									// Calculates ping value
		int 	SetPing(int ping);							// Set ping value to ping
		
		
		int 	Len;										// Length of the DUML data field 
		int 	Version;									// Protocol version
		int 	Crc8;										// Calculated CRC8 result
		int 	Crc8Sent;									// Transmitted CRC8 value
		int 	Crc16[2];									// Calculated CRC16 result (2 bytes)
		int 	Crc16Sent[2];								// Transmitted CRC16 result (2 bytes)
		int		SenderID;									// SenderID
		int 	SenderType;									// SenderType
		int		ReceiverID;									// ReceiverID
		int 	ReceiverType;								// ReceiverType
		int		Seq = 0;									// Sequence numer 
		int 	CMDSet;										// Command set
		int 	CMDID;										// Command ID
		int 	CMDType;									// Command Type
		int 	ACK;										// ACK value
		int 	CellVoltages[6];							// Cell voltages [mV] (max. 6 cells)
		int 	Voltage;									// Voltage of the battery [mV]
		int 	Current;									// Current flow [mA]
		int 	Capacity;									// Remaining capacity [mAh]
		int 	DesignCapacity;								// Design capacity [mAh]
		int 	Temperature;								// Temperature x 10 [°C]
		int		Percent;									// Remaining battery percentage
		int 	Unknown1;									// Unknown parameter 1
		int 	Unknown2;									// Unknown parameter 1
		
		bool 	Header;										// Header valid
		bool 	Valid;										// DUML valid
		
};



#endif