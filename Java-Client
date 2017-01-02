package serial_socket;

import java.io.IOException;
import java.io.InputStream;
import java.net.InetSocketAddress;
import java.net.Socket;

import jssc.SerialPort;
import jssc.SerialPortException;

public class Client {
	
	SerialPort sp;
	final String COM = "COM14";
	final int BYTE_NUMBER = 4;
	
	final String HOST = "localhost";
	final int PORT = 9999;
	
	Socket conn;
	InputStream is;
	
	public Client() {
		
		// Create serial port object
		sp = new SerialPort(COM);
		conn = new Socket();
		
	}
	
	public void receiveData() {
		
		try {
			conn.connect(new InetSocketAddress(HOST, PORT));
			System.out.println("[+] Connected to " + conn.getInetAddress() + ":" + conn.getPort());
			is = conn.getInputStream();
			byte[] data = new byte[BYTE_NUMBER];
			
			while(System.in.available() == 0) {
				is.read(data, 0, BYTE_NUMBER);
				System.out.println(new String(data));
				sp.writeBytes(data);
			}
		
			sp.closePort();
			conn.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		} catch (SerialPortException e) {
			e.printStackTrace();
		}
	}

	public void startSerialPort() {
		
		try {
			sp.openPort();
			sp.setParams(SerialPort.BAUDRATE_9600,
			        SerialPort.DATABITS_8,
			        SerialPort.STOPBITS_1,
			        SerialPort.PARITY_NONE);
			sp.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN | 
                    SerialPort.FLOWCONTROL_RTSCTS_OUT);
		} catch (SerialPortException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String args[]) throws IOException, InterruptedException, SerialPortException {
		
		Client client = new Client();
		client.startSerialPort();
		client.receiveData();
	
	}
		
}

	
