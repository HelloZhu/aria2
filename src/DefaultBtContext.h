/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef _D_DEFAULT_BT_CONTEXT_H_
#define _D_DEFAULT_BT_CONTEXT_H_

#include "BtContext.h"
#include "Dictionary.h"
#include "Data.h"
#include "List.h"
#define INFO_HASH_LENGTH 20
#define PIECE_HASH_LENGTH 20

typedef Strings PieceHashes;

class DefaultBtContext : public BtContext {
private:
  unsigned char infoHash[INFO_HASH_LENGTH];
  string infoHashString;
  PieceHashes pieceHashes;
  FileEntries fileEntries;
  FILE_MODE fileMode;
  long long int totalLength;
  int pieceLength;
  string name;
  int numPieces;
  string peerId;
  AnnounceTiers announceTiers;

  void clear();
  void extractPieceHash(const unsigned char* hashData,
			int hashDataLength,
			int hashLength);
  void extractFileEntries(Dictionary* infoDic,
			  const string& defaultName);
  void extractAnnounce(Data* announceData);
  void extractAnnounceList(List* announceListData);
 public:
  DefaultBtContext();
  virtual ~DefaultBtContext();

  virtual const unsigned char* getInfoHash() const;

  virtual int getInfoHashLength() const;

  virtual string getInfoHashAsString() const;

  virtual string getPieceHash(int index) const;

  virtual const Strings& getPieceHashes() const
  {
    return pieceHashes;
  }

  virtual long long int getTotalLength() const;

  virtual FILE_MODE getFileMode() const;

  virtual FileEntries getFileEntries() const;

  virtual AnnounceTiers getAnnounceTiers() const;

  virtual void load(const string& torrentFile);

  virtual string getName() const;

  virtual int getPieceLength() const;
  
  virtual int getNumPieces() const;

  virtual const unsigned char* getPeerId() {
    if(peerId == "") {
      peerId = generatePeerId();
    }
    return (const unsigned char*)peerId.c_str();
  }

  string generatePeerId() const;
};

#endif // _D_DEFAULT_BT_CONTEXT_H_
