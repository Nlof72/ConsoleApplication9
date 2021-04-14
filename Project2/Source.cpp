#include <matplot/matplot.h>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <string>
#include <wchar.h>
#include <set>
#include <cmath>


using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;
using namespace matplot;

namespace MatplotLibCLR {
	public ref class Graph {
	public:
		void Plot(array<double>^ x, array<double>^ y, System::String^ m) {
			std::vector<double> x1(x->Length);
			for (int i = 0; i < x->Length; i++) {
				x1[i] = x[i];
			}
			std::vector<double> y1(y->Length);
			for (int i = 0; i < y->Length; i++) {
				y1[i] = y[i];
			}
			char* m1 = (char*)(void*)Marshal::StringToHGlobalAnsi(m);
			plot(x1,y1,m1);
		}
		void Plot(array<double>^ x, array<double>^ y) {
			std::vector<double> x1(x->Length);
			for (int i = 0; i < x->Length; i++) {
				x1[i] = x[i];
			}
			std::vector<double> y1(y->Length);
			for (int i = 0; i < y->Length; i++) {
				y1[i] = y[i];
			}
			plot(x1,y1);
		}
		void Plot(array<double>^ y, System::String^ m) {
			std::vector<double> y1(y->Length);
			for (int i = 0; i < y->Length; i++) {
				y1[i] = y[i];
			}
			char* m1 = (char*)(void*)Marshal::StringToHGlobalAnsi(m);
			plot(y1,m1);
		}
		void Plot(array<double>^ y) {
			std::vector<double> y1(y->Length);
			for (int i = 0; i < y->Length; i++) {
				y1[i] = y[i];
			}
			plot(y1);
		}
		//void Plot(array<double, 2>^ y) {
		//	double** y1 = new double *[y->GetUpperBound(0)];
		//	for (int i = 0; i <= y->GetUpperBound(0); i++) {
		//		y1[i] = new double[y->GetUpperBound(1)];
		//	}
		//	for (int i = 0; i <= y->GetUpperBound(0); i++) {
		//		for (int j = 0; j <= y->GetUpperBound(1); j++) {
		//			y1[i][j] = y[i, j];
		//			std::cout << y1[i][j]<< " ";
		//		}
		//		std::cout << std::endl;
		//	}
		//	std::cout << std::endl;
		//	//std::cout << y->GetUpperBound(0)<< y->GetUpperBound(1);
		//	plot(y1);
		//}
		void Plot3(array<double>^ st, array<double>^ ct, array<double>^ t) {
			std::vector<double> st1(st->Length);
			for (int i = 0; i < st->Length; i++) {
				st1[i] = st[i];
			}
			std::vector<double> ct1(ct->Length);
			for (int i = 0; i < ct->Length; i++) {
				ct1[i] = ct[i];
			}
			std::vector<double> t1(t->Length);
			for (int i = 0; i < t->Length; i++) {
				t1[i] = t[i];
			}
			//char* m1 = (char*)(void*)Marshal::StringToHGlobalAnsi(m);
			plot3(st1, ct1, t1);
		}

		void Hold(bool param) {
			hold(param);
		}
		void Show() {
			show();
		}
		array<double>^ Linspace(double x1, double x2) {
			std::vector<double> x = linspace(x1, x2);
			array<double>^ xx = gcnew array<double>(x.size());
			for (int i = 0; i < x.size(); i++) {
				xx[i] = x[i];
			}
			return xx;
		}

		array<double>^ Iota(double lowerBound,double step, double upperBound) {
			std::vector<double> x = iota(lowerBound, step, upperBound);
			array<double>^ xx = gcnew array<double>(x.size());
			for (int i = 0; i < x.size(); i++) {
				xx[i] = x[i];
			}
			return xx;
		}
		array<double>^ Iota(double lowerBound, double upperBound) {
			std::vector<double> x = iota(lowerBound, upperBound);
			array<double>^ xx = gcnew array<double>(x.size());
			for (int i = 0; i < x.size(); i++) {
				xx[i] = x[i];
			}
			return xx;
		}
	};
}