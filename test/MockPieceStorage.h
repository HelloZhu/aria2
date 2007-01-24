#ifndef _D_MOCK_PIECE_STORAGE_H_
#define _D_MOCK_PIECE_STORAGE_H_

#include "PieceStorage.h"
#include "BitfieldMan.h"

class MockPieceStorage : public PieceStorage {
private:
  long long int totalLength;
  long long int filteredTotalLength;
  long long int completedLength;
  long long int filteredCompletedLength;
  BitfieldMan* bitfieldMan;
  bool selectiveDownloadingMode;
  bool endGame;
  DiskAdaptorHandle diskAdaptor;
  Integers pieceLengthList;
public:
  MockPieceStorage():diskAdaptor(0) {}
  virtual ~MockPieceStorage() {}

  virtual bool hasMissingPiece(const PeerHandle& peer) {
    return false;
  }

  virtual PieceHandle getMissingPiece(const PeerHandle& peer) {
    return new Piece();
  }

  virtual PieceHandle getMissingFastPiece(const PeerHandle& peer) {
    return new Piece();
  }

  virtual PieceHandle getPiece(int index) {
    return new Piece();
  }

  virtual void completePiece(const PieceHandle& piece) {}

  virtual void cancelPiece(const PieceHandle& piece) {}

  virtual bool hasPiece(int index) {
    return false;
  }

  virtual long long int getTotalLength() {
    return totalLength;
  }

  void setTotalLength(long long int totalLength) {
    this->totalLength = totalLength;
  }

  virtual long long int getFilteredTotalLength() {
    return filteredTotalLength;
  }

  void setFilteredTotalLength(long long int totalLength) {
    this->filteredTotalLength = totalLength;
  }

  virtual long long int getCompletedLength() {
    return completedLength;
  }

  void setCompletedLength(long long int completedLength) {
    this->completedLength = completedLength;
  }

  virtual long long int getFilteredCompletedLength() {
    return filteredCompletedLength;
  }

  void setFilteredCompletedLength(long long int completedLength) {
    this->filteredCompletedLength = completedLength;
  }
  
  virtual void setFileFilter(const Strings& filePaths) {}

  virtual void setFileFilter(const Integers& fileIndexes) {}

  virtual void clearFileFilter() {}

  virtual bool downloadFinished() {
    return false;
  }

  virtual void initStorage() {}

  virtual const unsigned char* getBitfield() {
    return bitfieldMan->getBitfield();
  }

  virtual void setBitfield(const unsigned char* bitfield,
			   int bitfieldLength) {
    bitfieldMan->setBitfield(bitfield, bitfieldLength);
  }
  
  virtual int getBitfieldLength() {
    return bitfieldMan->getBitfieldLength();
  }

  void setBitfield(BitfieldMan* bitfieldMan) {
    this->bitfieldMan = bitfieldMan;
  }

  virtual bool isSelectiveDownloadingMode() {
    return selectiveDownloadingMode;
  }

  void setSelectiveDownloadingMode(bool flag) {
    this->selectiveDownloadingMode = flag;
  }

  virtual void finishSelectiveDownloadingMode() {}

  virtual bool isEndGame() {
    return endGame;
  }

  void setEndGame(bool flag) {
    this->endGame = flag;
  }

  virtual DiskAdaptorHandle getDiskAdaptor() {
    return diskAdaptor;
  }

  void setDiskAdaptor(const DiskAdaptorHandle adaptor) {
    this->diskAdaptor = adaptor;
  }
  
  virtual int getPieceLength(int index) {
    return pieceLengthList.at(index);
  }

  void addPieceLengthList(int length) {
    pieceLengthList.push_back(length);
  }

  virtual void advertisePiece(int cuid, int index) {}

  virtual Integers getAdvertisedPieceIndexes(int myCuid,
					     const Time& lastCheckTime) {
    return Integers();
  }

  virtual void removeAdvertisedPiece(int elapsed) {}

  virtual void markAllPiecesDone() {}

  virtual void checkIntegrity() {}
};

typedef SharedHandle<MockPieceStorage> MockPieceStorageHandle;

#endif // _D_MOCK_PIECE_STORAGE_H_
