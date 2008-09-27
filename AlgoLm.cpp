#include "AlgoLm.h"


AlgoLm::AlgoLm() : AbstractAlgo() 
{

}


QByteArray AlgoLm::hash(const QByteArray* data) const
{
    std::cout << "Lm" << std::endl;
/* setup LanManager password */

    // char  lm_pw[14];
    unsigned char  lm_pw[14];
    // int   len = strlen(data->constData());
    int   len = data->size();
    if (len > 14)  len = 14;

    for (int idx=0; idx<len; idx++)
        lm_pw[idx] = toupper(data->at(idx));
    for (int idx=len; idx<14; idx++)
        lm_pw[idx] = 0;

    /* create LanManager hashed password */

    unsigned char magic[] = { 0x4B, 0x47, 0x53, 0x21, 0x40, 0x23, 0x24, 0x25 };
    unsigned char lm_hpw[21];
    des_key_schedule ks;

    setup_des_key(lm_pw, ks);
    // setup_des_key((unsigned char*)lm_pw, ks);
    des_ecb_encrypt((des_cblock*)magic, (des_cblock*)lm_hpw, ks, DES_ENCRYPT);

    setup_des_key(lm_pw+7, ks);
    // setup_des_key((unsigned char*)lm_pw+7, ks);
    // des_ecb_encrypt((des_cblock*)magic, lm_hpw+8, ks, DES_ENCRYPT);
    // FIXME: might be wrong
    des_ecb_encrypt((des_cblock*)magic, (des_cblock*)lm_hpw+8, ks, DES_ENCRYPT);

    memset(lm_hpw+16, 0, 5);
    QByteArray ba((char *)lm_hpw);

    return ba;
}


/*
 * turns a 56 bit key into the 64 bit, odd parity key and sets the key.
 * The key schedule ks is also set.
 */
void AlgoLm::setup_des_key(unsigned char key_56[], des_key_schedule ks) const
{
    des_cblock key;

    key[0] = key_56[0];
    key[1] = ((key_56[0] << 7) & 0xFF) | (key_56[1] >> 1);
    key[2] = ((key_56[1] << 6) & 0xFF) | (key_56[2] >> 2);
    key[3] = ((key_56[2] << 5) & 0xFF) | (key_56[3] >> 3);
    key[4] = ((key_56[3] << 4) & 0xFF) | (key_56[4] >> 4);
    key[5] = ((key_56[4] << 3) & 0xFF) | (key_56[5] >> 5);
    key[6] = ((key_56[5] << 2) & 0xFF) | (key_56[6] >> 6);
    key[7] =  (key_56[6] << 1) & 0xFF;

    des_set_odd_parity(&key);
    des_set_key(&key, ks);
}


// unsigned char * AlgoLm::hashSpeed(const QByteArray & data) const { }

/*
QByteArray AlgoLm::hashHumanReadable(const QByteArray & data) const
{
    return this->hash.toHex();
}
*/

bool AlgoLm::isValid(const QByteArray & hash) const
{
    if (hash.isEmpty() || hash.length() != 32)
        return FALSE;
    return TRUE;
}

