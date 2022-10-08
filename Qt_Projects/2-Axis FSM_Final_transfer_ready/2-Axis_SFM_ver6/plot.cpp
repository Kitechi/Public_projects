#include "plot.h"
#include <qwt_plot_grid.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_directpainter.h>
#include <qwt_curve_fitter.h>
#include <qwt_painter.h>
#include <qevent.h>
#include <QTimer.h>
#include <qwt_scale_widget.h>
#include <qwt_scale_engine.h>
#include <qwt_symbol.h>

Plot::Plot(QWidget *parent , bool vMarkEnArg, QString title,structSetting *settingInfoPtrArg):
    QwtPlot( parent )
{
    x_pt_d_loc = NULL;
    y_pt_d_loc = NULL;
    //d_directPainter = new QwtPlotDirectPainter();
    settingInfoPtr = settingInfoPtrArg;
    setAutoReplot( false );
    setCanvas( new QwtPlotCanvas() );
    plotLayout()->setAlignCanvasToScales( true );

    UpdatePlot();
    setTitle(title);

    //change the yaxis display

    qDebug()<<"Plot Axis Draw , Major Tick: "<<this->axisScaleDraw(xBottom)->tickLength(QwtScaleDiv::MajorTick)<<
                " Medium Tick: "<<this->axisScaleDraw(xBottom)->tickLength(QwtScaleDiv::MediumTick)<<
                " Minor Tick: "<<this->axisScaleDraw(xBottom)->tickLength(QwtScaleDiv::MinorTick);

    QwtScaleDraw *scaleDraw = new QwtScaleDraw();
    //scaleDraw->setTickLength( QwtScaleDiv::MajorTick,1 );
    //scaleDraw->setTickLength( QwtScaleDiv::MinorTick,  );
    //scaleDraw->setTickLength( QwtScaleDiv::MediumTick, 10 );
    //scaleDraw->setLength();

    this->setAxisScaleDraw(xBottom, scaleDraw);

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setPen( Qt::gray, 0.0, Qt::DotLine );
    grid->enableX( true );
    grid->enableXMin( true );
    grid->enableY( true );
    grid->enableYMin( false );
    grid->attach( this );

    d_curve = new QwtPlotCurve();
    d_curve->setStyle( QwtPlotCurve::Lines );
    d_curve->setPen( canvas()->palette().color( QPalette::WindowText ) );
    d_curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );
    d_curve->setPaintAttribute( QwtPlotCurve::ClipPolygons, false );
    //d_curve->setStyle(QwtPlotCurve::CurveStyle::Sticks);
    QwtSymbol *curveSymbol = new QwtSymbol(QwtSymbol::Style::Diamond);
    curveSymbol->setSize(1,1);
    d_curve->setSymbol(curveSymbol);
    d_curve->attach( this );

    if (this->vMarkEn = vMarkEnArg)
    {
        vertMarker = new QwtPlotMarker();
        //marker->setTitle( QString( "Event %1" ).arg( i + 1 ) );
        vertMarker->setLineStyle( QwtPlotMarker::VLine );
        vertMarker->setLinePen( Qt::blue, 2, Qt::SolidLine );
        vertMarker->attach( this );
        vertMarker->setVisible(false);
    }
    else
        vertMarker=NULL;


    zoomerV = new plotZoomer(this->canvas());
    pannerV = new QwtPlotPanner(this->canvas() );
    magnifierV = new QwtPlotMagnifier(this->canvas() );

    zoomerV->setMousePattern( QwtEventPattern::MouseSelect2,Qt::RightButton, Qt::ControlModifier );
    zoomerV->setMousePattern( QwtEventPattern::MouseSelect3,Qt::RightButton );
    const QColor c( Qt::darkBlue );
    zoomerV->setRubberBandPen( c );
    zoomerV->setTrackerPen( c );
    pannerV->setAxisEnabled( QwtPlot::yRight, false );
    pannerV->setMouseButton( Qt::MidButton );
    magnifierV->setAxisEnabled(2, false); //Magnification of X-axis is not allowed with the wheel
    initPlot();
}

void Plot::setPlotAttributes(QString title, QString yTitle, double yMin, double yMax, QString xTitle,
                             double xMin, double xMax)
{
    setTitle(title);
    setAxisTitle( QwtPlot::xBottom, xTitle );
    setAxisScale( QwtPlot::xBottom, xMin, xMax,0.5);

    setAxisTitle( QwtPlot::yLeft, yTitle );
    setAxisScale( QwtPlot::yLeft,yMin,yMax );

    decalreMemory();

    updateAxes();

}

Plot::~Plot()
{
   // delete d_curve;
   // if (vertMarker!=NULL)
    //    delete vertMarker;

    delete x_pt_d_loc;
    delete y_pt_d_loc;
}

void Plot::decalreMemory()
{
    if (x_pt_d_loc != NULL)
        delete x_pt_d_loc;
    if (y_pt_d_loc != NULL)
        delete y_pt_d_loc;

    x_pt_d_loc = new double[settingInfoPtr->PnaSweepPoints]();
    y_pt_d_loc = new double[settingInfoPtr->PnaSweepPoints]();
}

void Plot::updateAxisScale()
{
    int i;
    QwtScaleWidget *scaleWidget = axisWidget( QwtPlot::xBottom );
    const int fmh = QFontMetrics( scaleWidget->font() ).height();
    scaleWidget->setMinBorderDist( 0, fmh / 2 );


    setAxisTitle( QwtPlot::xBottom, "Frequency (GHz)" );
    //setAxisScale( QwtPlot::xBottom, 0, (double)((settingInfoPtr->PnaSweepPoints)));
    //setAxisScale( QwtPlot::xBottom, settingInfoPtr->PnaStartFreq, (double)settingInfoPtr->PnaStopFreq);
    setAxisScale( QwtPlot::xBottom, settingInfoPtr->PnaStartFreq, settingInfoPtr->PnaStopFreq,0.4);


    //setAxisTitle( QwtPlot::yLeft, "Level" );
    //setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine(10));
    setAxisScale( QwtPlot::yLeft,-50,5 );

    updateAxes();

    //for (int i=0;i<settingInfoPtr->PnaSweepPoints;i++)
        //x_pt_d_loc[i] = (double)((i))/(double)(settingInfoPtr->SamplingFreq); // initiate once

    //for (i=0;i<settingInfoPtr->PnaSweepPoints;i++)
        //x_pt_d_loc[i] = settingInfoPtr->PnaStartFreq+(settingInfoPtr->PnaFreqStepSize*i);

    //qDebug()<<"Plot::updateAxisScale() - frequency values";
    //for (i=0; i<10;i++)
        //qDebug()<<i<<x_pt_d_loc[i];
}

void Plot::UpdatePlot()
{
    switch(settingInfoPtr->selectedMeas)
    {
    case measType::er:
    case measType::ei:
    case measType::ur:
    case measType::ui:
        setPlotAttributes("","",-10,40,"Frequency(GHz)",settingInfoPtr->PnaStartFreq,
                          settingInfoPtr->PnaStopFreq);
        break;

    case measType::s11Mag:
    case measType::s21Mag:
        setPlotAttributes("","Log Mag",-40,10,"Frequency(GHz)",settingInfoPtr->PnaStartFreq,
                          settingInfoPtr->PnaStopFreq);
        break;

    default:
        break;

     }
}
void Plot::UpdateCurve(float *y_pt, QString Title,float *x_pt)
{
   int i;
   UpdatePlot();

   for (i=0;i<settingInfoPtr->PnaSweepPoints;i++)
        y_pt_d_loc[i] = (double)y_pt[i]; // just copy through pointer

   if (x_pt!=NULL)
   {
       for (i=0;i<settingInfoPtr->PnaSweepPoints;i++)
           x_pt_d_loc[i] = (double)x_pt[i]; // just copy through pointer
   }

   this->d_curve->setSamples(x_pt_d_loc,y_pt_d_loc,settingInfoPtr->PnaSweepPoints);

   if(this->vMarkEn)
       vertMarker->setVisible(true);
   if (Title!=NULL)
       setTitle(Title);

   replot();
}

void Plot::initPlot()
{
    setTitle("");
    for (int i=0;i<settingInfoPtr->PnaSweepPoints;i++)
         y_pt_d_loc[i] = 50000; //outside of the y-axis range

    this->d_curve->setSamples(x_pt_d_loc,y_pt_d_loc,settingInfoPtr->PnaSweepPoints);
    replot();
}

void Plot::updateVertMarker(int markerPos)
{
    //double vertMarkVal = settingInfoPtr->PnaStartFreq+(settingInfoPtr->PnaFreqStepSize*markerPos);
    double vertMarkVal = x_pt_d_loc[markerPos];
    vertMarker->setValue(vertMarkVal,0.0);
    replot();
    //qDebug()<<"Plot::verticleMarker"<<markerPos;
}

/*
void Plot::refreshPlot()
{
     replotRequested = false;
     replot();
}
*/
//dont need to re-define the virtual function
/*
void Plot::replot()
{
    CurveData *data = static_cast<CurveData *>( d_curve->data() );
    data->values().lock();

    QwtPlot::replot();
    d_paintedPoints = data->size();

    data->values().unlock();
}
*/

