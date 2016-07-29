#pragma once

namespace cc {
	
	class Session : public std::enable_shared_from_this<Session>, public Property
	{
	public:
		void handleWriteTimeout(const boost::system::error_code& nError);
		void handleWrite(const boost::system::error_code& nError);
		void internalWrite();
		void runWrite();
		
		void pushValue(ValuePtr& nValue);
		ValuePtr popValue();
		
		void runSend(ValuePtr& nValue);
		
		void handleRead(const boost::system::error_code& nError, size_t nBytes);
		void handleReadTimeout(const boost::system::error_code& nError);
		void internalRead(size_t nBytes);
		void runRead();
		
		virtual void runDisconnect();
		virtual void runException();
		virtual void runClose();
		
	public:
		enum { write_timeout = 150 };
		enum { read_timeout = 300 };
		
		Session(asio::io_service& nIoService);
		~Session();
		
	protected:
		asio::ip::tcp::socket mSocket;
		
		asio::deadline_timer mWriteTimer;
		asio::deadline_timer mReadTimer;
		
		boost::array<int8_t, PACKETSIZE> mReadBuffer;
		BufReader mBufReader;
		
		deque<ValuePtr> mValues;
		atomic<bool> mSending;
		BufWriter mBufWriter;
		
		bool mClosed;
	};
	typedef std::shared_ptr<Session> SessionPtr;
	typedef std::weak_ptr<Session> SessionWtr;
	
}
