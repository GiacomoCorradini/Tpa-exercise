# include <Matrix.h>
# include <DenseMatrix.h>
# include <SparseMatrix.h>

using std::cout;
using std::endl;

void conversions_example(){

    cout << endl;

    cout << "---- Conversions" << endl;

    cout << "pair2str(12,345): " << pair2str({12,345}) << endl;

    cout << "str2pair(\"12,345\"): " << pair2str(str2pair("12,345")) << endl;

    cout << "triplets2str<int>({{1,3,2}, {6,3,5}, {9,2,5}, {1,5,3}})"
         << triplets2str<int>({{1,3,2}, {6,3,5}, {9,2,5}, {1,5,3}}) << endl;

}

void dense_matrix_example(){

    cout << endl;
    cout << "---- DenseMatrix" << endl;

    vector<vector<int>> vmat = { {0,6,8,0}, {0,0,0,5}, {9,0,7,0} };

    cout << "dma = From vectors constructor:" << endl;

    DenseMatrix<int> dma = DenseMatrix<int>(vmat);

    Matrix<int>* pdma = &dma;

    cout << pdma->as_string() << endl;

    try {
        cout << "Trying to instantiate \n DenseMatrix<int>({{1,2},\n {3,4,5}}) ..." << endl;
        DenseMatrix<int> zdm = DenseMatrix<int>({{1,2}, {3,4,5}});
    } catch(std::invalid_argument& ex){
        cout << "something bad happened! " << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    }

    cout << "dma.shape(): " << pair2str(dma.shape()) << endl; // shape is a std::pair
    cout << "dma(1,3): " << dma(1,3) << endl;
    cout << "dma(1,3) += 9" << endl;

    dma(1,3) += 9;

    cout << pdma->as_string() << endl;
    cout << "dma.nonzero(): "<< triplets2str(dma.nonzero()) << endl;
    cout << endl;
    cout << "dmb = From triplets constructor:" << endl;

    Triplet<int> triplets[] = {{1,3,5},{2,1,8},{2,3,0},{2,0,-9},{0,0,7}};

    DenseMatrix<int> dmb = DenseMatrix<int>(3,4, triplets, 5);
    Matrix<int>* pdmb = &dmb;

    cout << pdmb->as_string() << endl;
    cout << endl;
    cout << "dmc = dma + dmb:" << endl;

    DenseMatrix<int> dmc = dma + dmb;

    Matrix<int>* pdmc = &dmc;

    cout << pdmc->as_string() << endl;
    cout << "Trying + with different dimensions..." << endl;

    try {
        dma + DenseMatrix<int>({{3,5,6}, {1,0,3}});
    } catch (std::invalid_argument& ex) {
        cout << "something bad happened! " << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    }

    cout << "dmc += dma" << endl;
    dmc += dma;
    cout << pdmc->as_string() << endl;
    cout << "Trying += with different dimensions..." << endl;

    try {
        dma += DenseMatrix<int>({{3,5}, {1,0}, {0,9}});
    } catch (std::invalid_argument& ex) {
        cout << "something bad happened! " << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    }
}

void sparse_matrix_example(){

    cout << endl;
    cout << "---- SparseMatrix" << endl;

    vector<vector<int>> vmat = { {0,6,8,0}, {0,0,0,5}, {9,0,7,0} };

    cout << "sma = From vectors constructor:" << endl;

    SparseMatrix<int> sma = SparseMatrix<int>(vmat);

    Matrix<int>* psma = &sma;

    cout << psma->as_string() << endl;

    try {
        cout << "Trying to instantiate \n SparseMatrix<int>({{0,2},\n {3,0,5}}) ..." << endl;
        SparseMatrix<int> zsm = SparseMatrix<int>({{0,2}, {3,0,5}});
    } catch(std::invalid_argument& ex){
        cout << "something bad happened! " << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    }

    cout << "sma.shape(): " << pair2str(sma.shape()) << endl; // shape is a std::pair
    cout << "sma(1,3): " << sma(1,3) << endl;
    cout << "sma(1,3) += 9" << endl;

    sma(1,3) += 9;

    cout << psma->as_string() << endl;
    cout << "sma.nonzero(): "<< triplets2str(sma.nonzero()) << endl;
    cout << endl;
    cout << "smb = From triplets constructor:" << endl;

    Triplet<int> triplets[] = {{1,3,5},{2,1,8},{2,3,0},{2,0,-9},{0,0,7}};

    SparseMatrix<int> smb = SparseMatrix<int>(3,4, triplets, 5);

    Matrix<int>* psmb = &smb;

    cout << psmb->as_string() << endl;
    cout << endl;
    cout << "smc = sma + smb:" << endl;

    SparseMatrix<int> smc = sma + smb;

    Matrix<int>* psmc = &smc;

    cout << psmc->as_string() << endl;
    cout << "Trying + with different dimensions..." << endl;

    try {
        sma + SparseMatrix<int>({{3,5,6}, {1,0,3}});
    } catch (std::invalid_argument& ex) {
        cout << "something bad happened! " << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    }

    cout << "smc += sma" << endl;

    smc += sma;

    cout << psmc->as_string() << endl;
    cout << "Trying += with different dimensions..." << endl;

    try {
    sma += SparseMatrix<int>({{3,5}, {1,0}, {0,9}});
    } catch (std::invalid_argument& ex) {
        cout << "something bad happened! " << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    }
}

int main(){

    // conversions_example();
    // dense_matrix_example();
    sparse_matrix_example();
}