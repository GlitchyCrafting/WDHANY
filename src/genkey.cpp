#include <cryptopp/cryptlib.h>
#include <cryptopp/rijndael.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>

int main() {
  CryptoPP::AutoSeededRandomPool asrp;
  CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(std::cout));
  CryptoPP::SecByteBlock key(CryptoPP::AES::BLOCKSIZE);
  asrp.GenerateBlock(key, key.size());
  encoder.Put(key, key.size());
  encoder.MessageEnd();
}
